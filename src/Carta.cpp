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
#include <iostream>

Carta::Carta(Simbolo::Valor valor, Simbolo::Naipe naipe):
    valor(valor),
    naipe(naipe)
{}

std::ostream& operator<<(std::ostream& os, const Carta& carta) {
    std::string espacoCondicional = carta.valor != Simbolo::Valor::DEZ ? " " : "";
    os << " [" << espacoCondicional
        << carta.formataValor()
        << static_cast<char>(carta.naipe) << "] ";
    return os;
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

std::string Carta::formataValor() const {
    switch (static_cast<int>(valor))
    {
    case 1:
        return "A";
        break;
    case 11:
        return "J";
        break;
    case 12:
        return "Q";
        break;
    case 13:
        return "K";
    default:
        return std::to_string(static_cast<int>(valor));
        break;
    }
}