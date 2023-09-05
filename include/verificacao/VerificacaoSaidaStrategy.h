#ifndef VERIFICACAO_SAIDA_STRATEGY_H
#define VERIFICACAO_SAIDA_STRATEGY_H
#include "Verificacao.h"

class VerificacaoSaidaStrategy : public Verificacao {
public:

    /**
     * @brief Constrói um novo objeto Verificação Saida Strategy.
     * 
     */
    VerificacaoSaidaStrategy() = default;

    /**
     * @brief Destrói o objeto Verificação Saida Strategy.
     * 
     */
    ~VerificacaoSaidaStrategy() = default;

    /**
     * @brief Verifica se a carta de topo na saida é imediatamente maior
     *  e de mesmo naipe do que a carta da coluna de origem.
     * 
     * @param colunaInicial Coluna de onde a carta sairia.
     * @param colunaFinal Coluna para onde a carta iria.
     * @param estrutura Estrutura que contém as cartas do jogo.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) override;
};

#endif