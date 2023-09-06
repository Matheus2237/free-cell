#include "../../include/verificacao/VerificacaoFactory.h"
#include "../../include/verificacao/VerificacaoColunaStrategy.h"
#include "../../include/verificacao/VerificacaoFreeCellStrategy.h"
#include "../../include/verificacao/VerificacaoSaidaStrategy.h"

Verificacao* VerificacaoFactory::criaVerificacao(unsigned short int colunaFinal) {
    if (colunaFinal == 0)
        return new VerificacaoSaidaStrategy();
    else if (colunaFinal >=1 && colunaFinal <= 8)
        return new VerificacaoColunaStrategy();
    else if (colunaFinal >= 9 && colunaFinal <= 12)
        return new VerificacaoFreeCellStrategy();
    return nullptr;
}