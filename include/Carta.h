#include "Simbolo.h"

#ifndef CARTA_H
#define CARTA_H

class Carta {
private:
    Simbolo::Valor valor;
    Simbolo::Naipe naipe;

public:

    /**
     * @brief Constrói um novo objeto Carta.
     * 
     */
    Carta() = default;

    /**
     * @brief Constrói um novo objeto Carta.
     * 
     * @param valor Valor da carta.
     * @param naipe Naipe da carta.
     */
    Carta(Simbolo::Valor valor, Simbolo::Naipe naipe);
    
    /**
     * @brief Destrói o objeto carta.
     * 
     */
    ~Carta() = default;

    [[deprecated("Método para imprimir carta será removido")]]
    void imprimeCarta() const;
};

#endif