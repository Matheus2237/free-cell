/**
 * @file Carta.cpp
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

#include "../include/Carta.h"
#include <sstream>

Carta::Carta(Simbolo::Valor valor, Simbolo::Naipe naipe):
    valor(valor),
    naipe(naipe)
{}

std::string Carta::toString() const {
    std::stringstream carta;
    std::string espacoCondicional = this->valor != Simbolo::Valor::DEZ ? " " : "";
    carta << " [" << static_cast<char>(this->naipe) << espacoCondicional
        << this->formataValor(static_cast<int>(this->valor))
        << static_cast<char>(this->naipe) << "] ";
    return carta.str();
}

std::string Carta::formataValor(const int valor) const {
    return std::to_string(valor);
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