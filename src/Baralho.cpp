/**
 * @file Baralho.cpp
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

#include "../include/Baralho.h"
#include <random>
#include <algorithm>

Baralho::Baralho() {
    for (int naipe = 0; naipe < QTDE_NAIPES; naipe++) {
        for (int valor = 0; valor < QTDE_VALORES; valor++) {
            unsigned int posicao_vetor = QTDE_VALORES * naipe + valor;
            this->cartas[posicao_vetor] = Carta(Simbolo::todos_valores[valor], Simbolo::todos_naipes[naipe]);
        }
    }
}

Baralho& Baralho::embaralhar() {
    std::shuffle(std::begin(this->cartas), std::end(this->cartas), std::mt19937(std::random_device()()));
    return *this;
}

Carta* Baralho::getCartas() {
    return this->cartas;
}