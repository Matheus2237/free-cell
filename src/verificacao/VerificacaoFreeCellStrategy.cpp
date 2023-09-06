#include "../../include/verificacao/VerificacaoFreeCellStrategy.h"
#include <iostream>

bool VerificacaoFreeCellStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura,
        const FreeCellGui& gui){

    if (estrutura.encontraUltimaCartaDaColuna(colunaFinal) != COLUNA_VAZIA) {
        gui.trataMovimentacaoProibida("Free cell já está cheia! Tente novamente.");
        return false;
    }
    return true;
}