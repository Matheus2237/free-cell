#include "Estrutura.h"
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
        cartas[iterador].setColuna(coluna);
    }
}


void Estrutura::imprimeCartas() const {
    for (int coluna = 5; coluna <= 12; coluna++) {
        std::cout << "Coluna " << coluna << ":" << std::endl;
        for (int carta = 0; carta < TAMANHO_BARALHO; carta++)
            if(cartas[carta].getColuna() == coluna)
                cartas[carta].imprimeCarta();
    }
}

// TODO: Implementar metodo
void Estrutura::movimenta(int inicial, int final) {

}