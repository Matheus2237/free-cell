#include <iostream>
#include <stdlib.h>
#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/FreeCellGui.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());
    FreeCellGui freeCellGui;
    freeCellGui.imprimeCartas(estrutura.getCartas());
    return 0;
}