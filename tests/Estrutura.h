#pragma once
#include "../include/Baralho.h"
#include "../include/Carta.h"

class Estrutura {
private:
    Carta* cartas;

public:
    Estrutura(Carta* cartas);
    void movimenta(unsigned int colunaInicial, unsigned int colunaFinal);
    void imprimeCartas() const;

private:
    void distribuiEmColunas();
    unsigned int encontraUltimaCartaDaColuna(unsigned int coluna);
};