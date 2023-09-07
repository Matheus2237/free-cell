#include "../include/FreeCellEngine.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"

#include <iostream>

// TODO: melhorar instanciacao do jogo
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
    Verificacao* verificacao;
    bool limpaErroPrimeiraLeitura = false;
    bool movimentacaoValida = false;
    while (!movimentacaoValida) {
        colunaInicial = interfaceGrafica.leColunaInicial(this->estrutura, limpaErroPrimeiraLeitura);
        colunaFinal = interfaceGrafica.leColunaFinal(colunaInicial);
        verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
        movimentacaoValida = verificacao->podeMovimentar(colunaInicial, colunaFinal, this->estrutura);
        if (!movimentacaoValida) {
            interfaceGrafica.trataMovimentacaoProibida(verificacao->getMensagemErro());
            limpaErroPrimeiraLeitura = true;
        }
        delete verificacao;
    }
    estrutura.movimenta(colunaInicial, colunaFinal);
    this->verificaSeGanhou(); // * Se ganhar, alterar o estado de jogoGanho para true 
}

void FreeCellEngine::verificaSeGanhou() {}

void FreeCellEngine::tearDown() {}