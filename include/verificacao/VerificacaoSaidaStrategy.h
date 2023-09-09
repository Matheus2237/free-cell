#ifndef VERIFICACAO_SAIDA_STRATEGY_H
#define VERIFICACAO_SAIDA_STRATEGY_H
#include "Verificacao.h"

class VerificacaoSaidaStrategy : public Verificacao {
private:
    const std::string mensagemErro = "Carta não pode ser movimentada para saída! Tente novamente.";
    
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