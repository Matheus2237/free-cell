#include "../include/Baralho.h"
#include "Estrutura.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());
    estrutura.imprimeCartas();
    estrutura.movimenta(6, 7);
    estrutura.imprimeCartas();
}