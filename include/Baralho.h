#ifndef BARALHO_H
#define BARALHO_H
#define TAMANHO_BARALHO 52
#include "Carta.h"

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


    /**
     * @brief Embaralha as cartas.
     * 
     */
    void embaralhar();

    /**
     * @brief Recupera o ponteiro para o vetor de cartas.
     * 
     * @return Carta* O ponteiro para o vetor de cartas.
     */
    Carta* getCartas();
};

#endif