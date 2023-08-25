#include "../include/Baralho.h"
#include "Estrutura.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());
    estrutura.imprimeCartas();
    
    estrutura.movimenta(6, 7); 
    estrutura.imprimeCartas();
    
    estrutura.movimenta(5, 8);
    estrutura.imprimeCartas();
    
    estrutura.movimenta(6, 9);
    estrutura.imprimeCartas();

    estrutura.movimenta(9, 8);
    estrutura.imprimeCartas();

    estrutura.movimenta(7, 6);
    estrutura.imprimeCartas();
}