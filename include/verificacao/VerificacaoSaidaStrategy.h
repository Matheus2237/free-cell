#ifndef VERIFICACAO_SAIDA_STRATEGY_H
#define VERIFICACAO_SAIDA_STRATEGY_H
#include "Verificacao.h"

class VerificacaoSaidaStrategy : public Verificacao {
private:
    const std::string mensagemErro = ""; // TODO: Escrever mensagem de erro a ser exibida no terminal
    
    bool valorImediatamenteMaior(const Carta cartaMovimentacao, const Carta cartaComparacao);

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
    [[deprecated("Metodo pode ser melhorado com a implementacao de outro metodo")]]
    bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) override;

    std::string getMensagemErro() const override;
};

#endif