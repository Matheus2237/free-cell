#ifndef VERIFICACAO_FREE_CELL_STRATEGY_H
#define VERIFICACAO_FREE_CELL_STRATEGY_H
#include "Verificacao.h"

class VerificacaoFreeCellStrategy : public Verificacao {
public:

    /**
     * @brief Constrói um novo objeto Verificação Free Cell Strategy.
     * 
     */
    VerificacaoFreeCellStrategy() = default;

    /**
     * @brief Destrói o objeto Verificação Free Cell Strategy.
     * 
     */
    ~VerificacaoFreeCellStrategy() = default;

    /**
     * @brief Verifica se a free cell na posição desejada está
     *  vazia.
     * 
     * @param colunaInicial Coluna de onde a carta sairia.
     * @param colunaFinal Coluna para onde a carta iria.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal) override;
};

#endif