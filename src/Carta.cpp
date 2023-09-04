#include "../include/Carta.h"
#include <iostream>
#include <locale.h>
#include <wchar.h>

Carta::Carta(Simbolo::Valor valor, Simbolo::Naipe naipe):
    valor(valor),
    naipe(naipe)
{}

// !!! Impressão está falhando -> Necessita mais testes
void Carta::imprimeCarta() const {
    setlocale(LC_ALL, "");
    std::wcout << "[ " <<
        static_cast<int>(this->valor) <<
        static_cast<wchar_t>(this->naipe) << 
        " ]" << " ";
}

unsigned int Carta::getColuna() const {
    return this->coluna;
}

void Carta::setColuna(unsigned int coluna) {
    this->coluna = coluna;
}

Simbolo::Naipe Carta::getNaipe() const {
    return this->naipe;
}

Simbolo::Valor Carta::getValor() const {
    return this->valor;
}