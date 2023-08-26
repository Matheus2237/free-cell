#include "../include/Baralho.h"
#include "../include/Estrutura.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());    
}