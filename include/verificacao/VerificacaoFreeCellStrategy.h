#ifndef VERIFICACAO_FREE_CELL_STRATEGY_H
#define VERIFICACAO_FREE_CELL_STRATEGY_H
#include "Verificacao.h"

class VerificacaoFreeCellStrategy : public Verificacao {
private:
    const std::string mensagemErro = "Free cell já está cheia! Tente novamente.";

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
     * @param estrutura Estrutura que contém as cartas do jogo.
     * @param gui Mecanismo de operações com o iterminal.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) override;

    /**
     * @brief Recupera a mensagem de erro.
     * 
     * @return std::string Mensagem de erro.
     */
    std::string getMensagemErro() const override;
};

#endif