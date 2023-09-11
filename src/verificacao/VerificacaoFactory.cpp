/**
 * @file VerificacaoFactory.cpp
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