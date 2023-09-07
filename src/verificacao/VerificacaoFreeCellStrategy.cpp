#include "../../include/verificacao/VerificacaoFreeCellStrategy.h"
#include <iostream>

bool VerificacaoFreeCellStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura){

    return estrutura.encontraUltimaCartaDaColuna(colunaFinal) == COLUNA_VAZIA;
}

std::string VerificacaoFreeCellStrategy::getMensagemErro() const {
    return this->mensagemErro;
}