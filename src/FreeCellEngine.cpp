#include "../include/FreeCellEngine.h"
#include "../include/Baralho.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"

FreeCellEngine::FreeCellEngine():
    jogoGanho(false),
    interfaceGrafica(FreeCellGui())
{
    this->setUp();
}

void FreeCellEngine::setUp() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());
}

bool FreeCellEngine::ganhou() const {
    return this->jogoGanho;
}

void FreeCellEngine::jogaProximaRodada() {
    interfaceGrafica.imprimeCartas(estrutura.getCartas());
    unsigned short int colunaInicial = interfaceGrafica.leColunaInicial(); // * Feita verificação se a coluna não está vazia. Esse método pode internamente chamar o método privado leColuna genérico.
    unsigned short int colunaFinal = interfaceGrafica.leColunaFinal(colunaInicial); // * Feita verificação se é a mesma coluna que a inicial. Esse método pode internamente chamar o método privado leColuna genérico.
    Verificacao* verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
    if (verificacao->podeMovimentar(colunaInicial, colunaFinal))
        estrutura.movimenta(colunaInicial, colunaFinal);
    // * Implementar impressão na tela de não ser possível realizar movimentação
    delete verificacao;
    this->verificaSeGanhou(); // * Se ganhar, alterar o estado de jogoGanho para true 
}

void FreeCellEngine::verificaSeGanhou() {}

void FreeCellEngine::tearDown() {}