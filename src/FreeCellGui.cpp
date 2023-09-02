#include "../include/FreeCellGui.h"
#include <iostream>

void FreeCellGui::imprimeCartas(Carta* cartas) const {
    for (int coluna = 5; coluna <= 12; coluna++) {
        std::cout << "Coluna " << coluna << ":" << std::endl;
        for (int carta = 0; carta < TAMANHO_BARALHO; carta++)
            if(cartas[carta].getColuna() == coluna)
                cartas[carta].imprimeCarta();
    }
    std::cout << std::endl << std::endl;
}

unsigned short int FreeCellGui::leColunaInicial() {}

unsigned short int FreeCellGui::leColunaFinal(unsigned short int colunaInicial) {}

unsigned short int FreeCellGui::leColuna() {}