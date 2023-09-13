/**
 * @file Verificacao.h
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

#ifndef VERIFICACAO_H
#define VERIFICACAO_H
#include "../Carta.h"
#include "../Mesa.h"
#include <string>

/**
 * @brief Interface abstrata para verificar se movimentações ocorrentes no jogo
 *  são ações permitidas de serem tomadas.
 * 
 * Abstrai o design pattern Strategy. O método podeMovimentar() deve ser sobrescrito
 * nas classes filhas para implementar a regra de validação de movimentação. Possui também o
 * método getMensagemErro para recuperar a mensagem de erro a ser exibida caso a movimentação
 * seja ilegal.
 * 
 */
class Verificacao {
public:

    /**
     * @brief Construtor padrão para o objeto Verificação.
     * 
     */
    Verificacao() = default;

    /**
     * @brief Destrutor padrão para o objeto verificação.
     * 
     */
    ~Verificacao() = default;

    /**
     * @brief Verifica se a carta de uma coluna pode ser movimentada para uma
     *  outra coluna. O critério de permissão se baseia na coluna de destino.
     * 
     * @param colunaInicial Coluna de onde a carta sairia.
     * @param colunaFinal Coluna para onde a carta iria.
     * @param mesa Mesa que contém as cartas do jogo.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    virtual bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Mesa& mesa) = 0;

    /**
     * @brief Recupera a mensagem de erro.
     * 
     * @return std::string Mensagem de erro.
     */
    virtual std::string getMensagemErro() const = 0;
};

#endif