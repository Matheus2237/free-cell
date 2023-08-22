#include <iostream>
#include <stdlib.h>
#include "../include/Baralho.h"

int main() {
    Baralho baralho;
    baralho.imprimeCartas();

    std::cout << "Embaralhando..." << std::endl;
    baralho.embaralhar();
    baralho.imprimeCartas();

    return 0;
}