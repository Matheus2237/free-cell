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
    interfaceGrafica.imprimeCartas(estrutura.getCartas());
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