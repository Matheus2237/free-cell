/**
 * @file Mesa.cpp
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

#include "../include/Estrutura.h"

Mesa::Mesa(Carta* cartas):
    cartas(cartas)
{
    this->distribuiEmColunas();
}

void Mesa::distribuiEmColunas() {
    int coluna = 1;
    for(int iterador = 0; iterador < TAMANHO_BARALHO; iterador++) {
        if(iterador == 7 || iterador == 14 || iterador == 21 || iterador == 28 ||
                iterador == 34 || iterador == 40 || iterador == 46)
            coluna++;
        this->cartas[iterador].setColuna(coluna);
    }
}

void Mesa::movimenta(unsigned int colunaInicial, unsigned int colunaFinal) {
    unsigned int posicaoInicial = this->encontraUltimaCartaDaColuna(colunaInicial);
    Carta carta = this->cartas[posicaoInicial];
    carta.setColuna(colunaFinal);
    for (int i = posicaoInicial; i < TAMANHO_BARALHO-1; i++)
        this->cartas[i] = this->cartas[i+1];
    this->cartas[TAMANHO_BARALHO-1] = carta;
}

short int Mesa::encontraUltimaCartaDaColuna(unsigned int coluna) const {
    for (int i = TAMANHO_BARALHO-1; i >= 0; i--)
        if (this->cartas[i].getColuna() == coluna)
            return i;
    return COLUNA_VAZIA;
}

short int Mesa::encontraUltimaCartaSaida(Simbolo::Naipe naipe) const {
    for (int i = TAMANHO_BARALHO-1; i >= 0; i--)
        if (this->cartas[i].getColuna() == 0 && this->cartas[i].getNaipe() == naipe)
            return i;
    return COLUNA_VAZIA;
}

Carta* Mesa::getCartas() const {
    return this->cartas;
}