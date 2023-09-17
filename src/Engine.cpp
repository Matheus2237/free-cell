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
#include "../include/MovimentacaoIndevidaException.h"

Engine::Engine(const Mesa& mesa):
    jogoGanho(false),
    mesa(mesa)
{}

void Engine::jogaPartida() {
    Engine engine(Mesa(Baralho().embaralhar().getCartas()));
    while(!engine.ganhou())
        engine.jogaProximaRodada();
    InterfaceDeUsuario::finalizaPartida();
}

bool Engine::ganhou() const {
    return this->jogoGanho;
}

void Engine::jogaProximaRodada() {
    InterfaceDeUsuario::imprimeCartas(mesa);
    try {
        unsigned short int colunaInicial = InterfaceDeUsuario::leColunaInicial(this->mesa);
        unsigned short int colunaFinal = InterfaceDeUsuario::leColunaFinal(colunaInicial);
        Verificacao* verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
        if (verificacao->podeMovimentar(colunaInicial, colunaFinal, this->mesa)) {
            this->mesa.movimenta(colunaInicial, colunaFinal);
            this->verificaSeGanhou(); 
        } else
            InterfaceDeUsuario::imprimeMotivoErro(verificacao->getMensagemErro().c_str());
        delete verificacao;
    } catch(MovimentacaoIndevidaException& mie) {
        InterfaceDeUsuario::imprimeMotivoErro(mie.what());
    }
}

void Engine::verificaSeGanhou() {
    for (int naipe = 0; naipe < Simbolo::QTDE_NAIPES; naipe++)
        if (this->mesa.getCartas()[this->mesa.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe])]
                .getValor() != Simbolo::Valor::REI)
            return;
    this->jogoGanho = true;
}

void Engine::verificaSePerdeu() {
    if(mesa.checaMovimentacoesPossiveis() == 0){
        
    }
}

