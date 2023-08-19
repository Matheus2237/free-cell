#include "Simbolo.h"

#ifndef CARTA_H
#define CARTA_H

class Carta {
private:
    Simbolo::Valor valor;
    Simbolo::Naipe naipe;

public:
    Carta(Simbolo::Valor valor, Simbolo::Naipe naipe);
    ~Carta();
};

#endif