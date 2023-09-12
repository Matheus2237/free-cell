/**
 * @file FreeCellEngine.cpp
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

#include "../include/FreeCellEngine.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"

#include <iostream>

FreeCellEngine::FreeCellEngine(const Estrutura& estrutura):
    jogoGanho(false),
    interfaceGrafica(FreeCellGui()),
    estrutura(estrutura)
{}

bool FreeCellEngine::ganhou() const {
    return this->jogoGanho;
}

void FreeCellEngine::jogaProximaRodada() {
    interfaceGrafica.imprimeCartas(estrutura);
    unsigned short int colunaInicial;
    unsigned short int colunaFinal;
    bool limpaErroPrimeiraLeitura = false;
    bool movimentacaoValida = false;
    while (!movimentacaoValida) {
        colunaInicial = interfaceGrafica.leColunaInicial(this->estrutura, limpaErroPrimeiraLeitura);
        colunaFinal = interfaceGrafica.leColunaFinal(colunaInicial);
        Verificacao* verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
        movimentacaoValida = verificacao->podeMovimentar(colunaInicial, colunaFinal, this->estrutura);
        if (!movimentacaoValida) {
            interfaceGrafica.trataMovimentacaoProibida(verificacao->getMensagemErro());
            limpaErroPrimeiraLeitura = true;
        }
        delete verificacao;
    }
    this->estrutura.movimenta(colunaInicial, colunaFinal);
    this->verificaSeGanhou(); 
}

void FreeCellEngine::verificaSeGanhou() {
    for (int naipe = 0; naipe < QTDE_NAIPES; naipe++)
        if (this->estrutura.getCartas()[this->estrutura.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe])]
                .getValor() != Simbolo::Valor::REI)
            return;
    this->jogoGanho = true;
}


void FreeCellEngine::iniciaJogo() {
    FreeCellGui::exibeTitulo();
    FreeCellGui::exibeDevs();
    FreeCellGui::exibeRegras();
}

void FreeCellEngine::finalizaJogo() {
    FreeCellGui::exibeTrofeu();
}