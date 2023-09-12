/**
 * @file Baralho.h
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

#ifndef BARALHO_H
#define BARALHO_H
#define TAMANHO_BARALHO 52 /// Total de cartas de um baralho convencional.
#include "Carta.h"

/**
 * @brief Uma classe que representa um baralho.
 * 
 * A classe baralho é usada para instanciar as 52 cartas que compoem um baralho 
 * convencional. Possibilita que esse baralho seja embaralhado inúmeras vezes.
 * 
 */
class Baralho {
private:

    /**
     * @brief Vetor de cartas que contém as cartas referentes ao baralho.
     * 
     */
    Carta cartas[TAMANHO_BARALHO];

public:

    /**
    * @brief Constrói um novo objeto baralho.
    * 
    */
    Baralho();

    /**
    * @brief Destrói o objeto baralho.
    * 
    */
    ~Baralho() = default;


    /**
     * @brief Embaralha as cartas.
     * 
     * @return Baralho& A instância da própria classe.
     */
    Baralho& embaralhar();

    /**
     * @brief Recupera o ponteiro para o vetor de cartas.
     * 
     * @return Carta* O ponteiro para o vetor de cartas.
     */
    Carta* getCartas();
};

#endif