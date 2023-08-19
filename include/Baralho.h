#include "Carta.h"

#ifndef BARALHO_H
#define BARALHO_H
#define TAMANHO_BARALHO 52

class Baralho {
private:
    Carta cartas[TAMANHO_BARALHO];

public:

    /**
     * @brief Constrói um novo objeto baralho.
     * 
     */
    Baralho();

    /**
     * @brief Destrói o objeto baralho.
     * 
     */
    ~Baralho() = default;
};

#endif