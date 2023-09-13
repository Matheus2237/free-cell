/**
 * @file Engine.cpp
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/Engine.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"
#include "../include/InterfaceDeUsuario.h"

Engine::Engine(const Mesa& mesa):
    jogoGanho(false),
    mesa(mesa)
{}

bool Engine::ganhou() const {
    return this->jogoGanho;
}

void Engine::jogaProximaRodada() {
    InterfaceDeUsuario::imprimeCartas(mesa);
    unsigned short int colunaInicial;
    unsigned short int colunaFinal;
    bool limpaErroPrimeiraLeitura = false;
    bool movimentacaoValida = false;
    while (!movimentacaoValida) {
        colunaInicial = InterfaceDeUsuario::leColunaInicial(this->mesa, limpaErroPrimeiraLeitura);
        colunaFinal = InterfaceDeUsuario::leColunaFinal(colunaInicial);
        Verificacao* verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
        movimentacaoValida = verificacao->podeMovimentar(colunaInicial, colunaFinal, this->mesa);
        if (!movimentacaoValida) {
            InterfaceDeUsuario::trataMovimentacaoProibida(verificacao->getMensagemErro());
            limpaErroPrimeiraLeitura = true;
        }
        delete verificacao;
    }
    this->mesa.movimenta(colunaInicial, colunaFinal);
    this->verificaSeGanhou(); 
}

void Engine::verificaSeGanhou() {
    for (int naipe = 0; naipe < Simbolo::QTDE_NAIPES; naipe++)
        if (this->mesa.getCartas()[this->mesa.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe])]
                .getValor() != Simbolo::Valor::REI)
            return;
    this->jogoGanho = true;
}


void Engine::iniciaJogo() {
    InterfaceDeUsuario::exibeTitulo();
    InterfaceDeUsuario::exibeDevs();
    InterfaceDeUsuario::exibeRegras();
}

void Engine::finalizaJogo() {
    InterfaceDeUsuario::exibeTrofeu();
}