/**
 * @file Carta.h *
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CARTA_H
#define CARTA_H
#include "Simbolo.h"
#include <string>

/**
 * @brief Classe que implementa as cartas do baralho.
 * 
 * Implementa as cartas do baralho, com seus respectivos valores e naipes.
 * 
*/
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
     * @brief Destrói o objeto carta.
     * 
     */
    ~Carta() = default;

    /**
     * @brief Sobrecarga do operador de fluxo << para que o cout possa receber um
     *  objeto do tipo Carta para imprimi-lo.
     * 
     * @overload
     */
    friend std::ostream& operator<<(std::ostream& cout, const Carta& carta);

    /**
    * @brief Recupera o atributo naipe.
    * 
    * @return Simbolo::Naipe.
    */
    Simbolo::Naipe getNaipe() const;
    
    /**
     * @brief Recupera o atributo valor.
     * 
     * @return Simbolo::Valor.
    */
    Simbolo::Valor getValor() const;

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

private:

    [[deprecated("Implementar formatação dos valores das cartas")]]
    std::string formataValor() const;
};

#endif