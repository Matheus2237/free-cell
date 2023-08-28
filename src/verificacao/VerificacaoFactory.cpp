#include "../../include/verificacao/VerificacaoFactory.h"
#include "../../include/verificacao/VerificacaoColunaStrategy.h"
#include "../../include/verificacao/VerificacaoFreeCellStrategy.h"
#include "../../include/verificacao/VerificacaoSaidaStrategy.h"

Verificacao* VerificacaoFactory::criaVerificacao(unsigned short int colunaFinal) {
    if (colunaFinal == 0)
        return new VerificacaoSaidaStrategy();
    else if (colunaFinal >=1 && colunaFinal <= 4)
        return new VerificacaoFreeCellStrategy();
    else if (colunaFinal >= 5 && colunaFinal <= 12)
        return new VerificacaoColunaStrategy();
    return nullptr;
}