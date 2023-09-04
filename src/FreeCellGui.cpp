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

unsigned short int FreeCellGui::leColunaInicial(const Estrutura& estrutura) {
    const std::string mensagemLeitura = "Entre o valor da coluna inicial: ";
    unsigned short int colunaInicial;
    bool colunaValida = false;
    while (!colunaValida) {
        colunaInicial = this->leColuna(mensagemLeitura);
        if (colunaInicial == 0) {
            CLEAR_LINE;
            std::cout << "Não pode mover carta da saída, tente novamente. ";
            continue;
        }
        colunaValida = true;
    }
    return colunaInicial;
}

unsigned short int FreeCellGui::leColunaFinal(unsigned short int colunaInicial) {}

unsigned short int FreeCellGui::leColuna(const std::string mensagemLeitura) {
    unsigned short int coluna;
    std::string colunaString;
    const std::string mensagemErro = "Coluna invalida, tente novamente. ";
    bool colunaValida = false;
    while(!colunaValida) {
        std::cout << mensagemLeitura;
        std::getline(std::cin, colunaString);
        if (colunaString.empty() || !this->somenteNumeros(colunaString)) {
            CLEAR_LINE;
            std::cout << mensagemErro;
            continue;
        }
        coluna = std::stoi(colunaString);
        if (coluna < 0 || coluna > 12) {
            CLEAR_LINE;
            std::cout << mensagemErro;
            continue;
        }
        colunaValida = true;
    }
    return coluna;
}

bool FreeCellGui::somenteNumeros(std::string colunaString) {
    for (int i = 0; i < colunaString.length(); i++)
        if(!isdigit(colunaString[i]))
            return false;
    return true;
}