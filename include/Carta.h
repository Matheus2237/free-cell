#include "Naipe.h"
#include "Valor.h"

#ifndef CARTA_H
#define CARTA_H

class Carta {
private:
    Valor valor;
    Naipe naipe;

public:
    Carta(Valor valor, Naipe naipe);
    ~Carta();
};

#endif