#include "../include/FreeCellEngine.h"
#include "../include/Baralho.h"

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

bool FreeCellEngine::ganhou() {
    return this->jogoGanho;
}

void FreeCellEngine::jogaProximaRodada() {
    // * Imprimir na tela o estado do baralho
    unsigned short int colunaInicial = interfaceGrafica.leColunaInicial(); // * Feita verificação se a coluna não está vazia. Esse método pode internamente chamar o método privado leColuna genérico.
    unsigned short int colunaFinal = interfaceGrafica.leColunaFinal(colunaInicial); // * Feita verificação se é a mesma coluna que a inicial. Esse método pode internamente chamar o método privado leColuna genérico.
    // * Verificacao verificacao = VerificacaoFactory::recuperaVerificacao(colunaFinal);
    // * if (verificacao.podeMovimentar())
    // *    estrutura.movimenta(colunaInicial, colunaFinal);
    this->verificaSeGanhou(); // * Se ganhar, alterar o estado de jogoGanho para true 
}

void FreeCellEngine::verificaSeGanhou() {}

void FreeCellEngine::tearDown() {}