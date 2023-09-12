/**
 * @file VerificacaoColunaStrategy.h
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

#ifndef VERIFICACAO_COLUNA_STRATEGY_H
#define VERIFICACAO_COLUNA_STRATEGY_H
#include "Verificacao.h"

/**
 * @brief Classe que implementa a estratégia de verificação de movimentação definida na 
 * interface da classe base puramente virtual "Verificacao".
 * 
 * Implementa a regra de verificação de movimentação de uma coluna ou free cell para uma outra
 * coluna do jogo. Sobrescreve os métodos podeMovimentar - responsável por verificar a 
 * movimentação - e getMensagemErro - o qual retorna a mensagem de erro a ser utilizada caso a movimentação
 * não seja permitida.
 * 
 */
class VerificacaoColunaStrategy : public Verificacao {
private:

    /// Mensagem a ser exibida em caso de não permissão de movimentação para uma coluna do jogo.
    const std::string mensagemErro = "Carta não pode ser movimentada entre as pilhas! Tente novamente.";

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

private:

    /**
     * @brief Verifica se a carta de destino é de cor diferente da carta final
     * 
     * @param cartaMovimentacao Carta inicial.
     * @param cartaComparacao Carta final.
     * @return true se as cartas forem de cores diferentes. 
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