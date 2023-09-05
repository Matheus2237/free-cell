#ifndef VERIFICACAO_COLUNA_STRATEGY_H
#define VERIFICACAO_COLUNA_STRATEGY_H
#include "Verificacao.h"

class VerificacaoColunaStrategy : public Verificacao {
public:

    /**
     * @brief Constrói um novo objeto Verificação Coluna Strategy.
     * 
     */
    VerificacaoColunaStrategy() = default;

    /**
     * @brief Destrói o objeto Verificação Coluna Strategy.
     * 
     */
    ~VerificacaoColunaStrategy() = default;

    /**
     * @brief Verifica se a carta da coluna de destino é imediatamente menor
     *  e de cor diferente do que a carta da coluna de origem.
     * 
     * @param colunaInicial Coluna de onde a carta sairia.
     * @param colunaFinal Coluna para onde a carta iria.
     * @param estrutura Estrutura que contém as cartas do jogo.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    bool podeMovimentar(unsigned short int colunaInicial,
      unsigned short int colunaFinal, const Estrutura& estrutura) override;

private:

    /**
     * @brief Verifica se a carta de destino é de cor diferente da carta final
     * 
     * @param cartaMovimentacao Carta inicial.
     * @param cartaComparacao Carta final.
     * @return true se as cartas forem diferentes. 
    */
    bool corDiferente(const Carta cartaMovimentacao, const Carta cartaComparacao);


    /**
     * @brief Verifica se a carta de destino é imediatamente menor que a carta final
     * 
     * @param cartaMovimentacao Carta inicial.
     * @param cartaComparacao Carta final.
     * @return true se a carta de destino for imediatamente menor que a carta final.
    */
    bool valorImediatamenteMenor(const Carta cartaMovimentacao, const Carta cartaComparacao);

};

#endif