#ifndef CARTA_H
#define CARTA_H
#include "Simbolo.h"

class Carta {
private:
    Simbolo::Valor valor;
    Simbolo::Naipe naipe;
    unsigned int coluna;

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
    *@brief Recupera o atributo naipe.
    * 
    *@return Simbolo::Naipe.
    */
    Simbolo::Naipe getNaipe() const;
    
    /**
     * @brief Recupera o atributo valor.
     * 
     * @return Simbolo::Valor.
    */
    Simbolo::Valor getValor() const;
    /**
     * @brief Destrói o objeto carta.
     * 
     */
    ~Carta() = default;

    [[deprecated("Método deve ser melhorado")]]
    void imprimeCarta() const;

    /**
     * @brief Recupera o atributo coluna.
     * 
     * @return unsigned int Valor da coluna.
     */
    unsigned int getColuna() const;

    /**
     * @brief Atribui o valor especificado ao atributo coluna.
     * 
     * @param coluna Valor a ser atribuido.
     */
    void setColuna(unsigned int coluna);
};

#endif