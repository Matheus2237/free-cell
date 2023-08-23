#pragma once
#include "../include/Baralho.h"
#include "../include/Carta.h"

class Estrutura {
private:
    Carta* cartas;

public:
    Estrutura(Carta* cartas);
    void movimenta(int inicial, int final);
    void imprimeCartas() const;

private:
    void distribuiEmColunas();
};