/**
 * @file Mesa.h
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

#ifndef MESA_H
#define MESA_H
#include "Baralho.h"
#include "Carta.h"

const int COLUNA_VAZIA = -1; /// Retornado quando não se encontra nenhuma carta referente a coluna indicada.

/**
 * @brief Classe que implementa a mesa do jogo.
 * 
 * Implementa a mesa do jogo, com metodos de movimentação de cartas e busca de cartas.
 * 
*/
class Mesa {
private:

    /**
     * @brief Ponteiro para o vetor de cartas.
     * 
     */
    Carta* cartas;

public:

    /**
     * @brief Constrói um novo objeto Mesa.
     * 
     */
    Mesa() = default;

    /**
     * @brief Constrói um novo objeto Mesa.
     * 
     * @param cartas Ponteiro para o vetor de cartas a comporem o jogo.
     */
    Mesa(Carta* cartas);

    /**
     * @brief Destrói o objeto Mesa.
     * 
     */
    ~Mesa() = default;

    /**
     * @brief Movimenta uma carta de uma coluna para outra.
     * 
     * @param colunaInicial Coluna inicial.
     * @param colunaFinal Coluna final.
     */
    void movimenta(unsigned int colunaInicial, unsigned int colunaFinal);

    /**
     * @brief Encontra a última carta de uma coluna.
     * 
     * @param coluna Coluna onde será realizada a busca.
     * @return short int Posição no vetor de cartas da carta encontrada.
     * @return COLUNA_VAZIA (-1) Posição que representa quando a coluna não possui cartas.
    */
    short int encontraUltimaCartaDaColuna(unsigned int coluna) const;

    /**
     * @brief Encontra a última carta de um determinado naipe das saídas do jogo.
     * 
     * @param naipe Naipe da carta a ser encontrado.
     * @return short int Posição desta carta no vetor.
     */
    short int encontraUltimaCartaSaida(Simbolo::Naipe naipe) const;
    
    /**
     * @brief Realiza a contagem de jogadas possiveis.
     * 
     * @return int Numero de jogadas possiveis
     */
    int checaMovimentacoesPossiveis();

    /**
     * @brief Retorna o vetor de cartas.
    */
    Carta* getCartas() const;

private:

    /**
     * @brief Atribui os valores iniciais das colunas nas cartas.
     * 
     */
    void distribuiEmColunas();
};

#endif