/**
 * @file VerificacaoFreeCellStrategy.h
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

#ifndef VERIFICACAO_FREE_CELL_STRATEGY_H
#define VERIFICACAO_FREE_CELL_STRATEGY_H
#include "Verificacao.h"

/**
 * @brief Classe que implementa a estratégia de verificação de movimentação definida na 
 * interface da classe base puramente virtual "Verificacao".
 * 
 * Implementa a regra de verificação de movimentação de uma coluna ou free cell para uma outra
 * coluna do jogo. Sobrescreve os métodos podeMovimentar - responsável por verificar a 
 * movimentação - e getMensagemErro - retorna a mensagem de erro a ser utilizada caso a movimentação
 * não seja permitida.
 * 
*/
class VerificacaoFreeCellStrategy : public Verificacao {
private:

    /// Mensagem a ser exibida em caso de não permissão de movimentação para a free cell.
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