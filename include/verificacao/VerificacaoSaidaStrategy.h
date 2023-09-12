/**
 * @file VerificacaoSaidaStrategy.h
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

#ifndef VERIFICACAO_SAIDA_STRATEGY_H
#define VERIFICACAO_SAIDA_STRATEGY_H
#include "Verificacao.h"

/**
 * @brief Classe que implementa a estratégia de verificação de movimentação definida na 
 * interface da classe base puramente virtual "Verificacao".
 * 
 * Implementa a regra de verificação de movimentação de uma coluna para a
 * coluna de saida. Sobrescreve os métodos podeMovimentar - responsável por verificar a 
 * movimentação - e getMensagemErro - o qual retorna a mensagem de erro a ser utilizada caso a movimentação
 * não seja permitida.
 * 
*/
class VerificacaoSaidaStrategy : public Verificacao {
private:

    /**
     * @brief Mensagem a ser exibida em caso de não permissão de movimentação para a saída.
     * 
     */
    const std::string mensagemErro = "Carta não pode ser movimentada para saída! Tente novamente.";

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
     * @param estrutura Mesa que contém as cartas do jogo.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Mesa& estrutura) override;

    /**
     * @brief Recupera a mensagem de erro.
     * 
     * @return std::string Mensagem de erro.
     */
    std::string getMensagemErro() const override;

private:

    /**
     * @brief Verifica se o valor da carta a ser movimentada é imediatamente maior
     *  do que o valor da maior carta da pilha de saída.
     * 
     * @param cartaMovimentacao Carta a ser movimentadao.
     * @param cartaComparacao Maior carta da pilha de saída;
     * @return true Caso a carta a ser movimentada seja imediatamente maior.
     * @return false Caso a carta a ser movimentada não seja imediatamente maior.
     */
    bool valorImediatamenteMaior(const Carta cartaMovimentacao, const Carta cartaComparacao);
};

#endif