#include "../include/Estrutura.h"
#include <iostream>

Estrutura::Estrutura(Carta* cartas):
    cartas(cartas)
{
    this->distribuiEmColunas();
}

void Estrutura::distribuiEmColunas() {
    int coluna = 5;
    for(int iterador = 0; iterador < TAMANHO_BARALHO; iterador++) {
        if(iterador == 7 || iterador == 14 || iterador == 21 || iterador == 28 ||
                iterador == 34 || iterador == 40 || iterador == 46)
            coluna++;
        this->cartas[iterador].setColuna(coluna);
    }
}


void Estrutura::imprimeCartas() const {
    for (int coluna = 5; coluna <= 12; coluna++) {
        std::cout << "Coluna " << coluna << ":" << std::endl;
        for (int carta = 0; carta < TAMANHO_BARALHO; carta++)
            if(this->cartas[carta].getColuna() == coluna)
                this->cartas[carta].imprimeCarta();
    }
    std::cout << std::endl << std::endl;
}

void Estrutura::movimenta(unsigned int colunaInicial, unsigned int colunaFinal) {
    unsigned int posicaoInicial = this->encontraUltimaCartaDaColuna(colunaInicial);
    Carta carta = this->cartas[posicaoInicial];
    carta.setColuna(colunaFinal);
    for (int i = posicaoInicial; i < TAMANHO_BARALHO-1; i++)
        this->cartas[i] = this->cartas[i+1];
    this->cartas[TAMANHO_BARALHO-1] = carta;
}

unsigned int Estrutura::encontraUltimaCartaDaColuna(unsigned int coluna) {
    for (int i = TAMANHO_BARALHO-1; i >= 0; i--)
        if (this->cartas[i].getColuna() == coluna)
            return i;
}