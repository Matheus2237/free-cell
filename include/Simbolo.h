/**
 * @file Simbolo.h
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

#ifndef SIMBOLO_H
#define SIMBOLO_H
#define QTDE_NAIPES 4 /// Quantidade total de naipes em um baralho convencional.
#define QTDE_VALORES 13 /// Quantidade total de valores em um baralho convecional.

/**
 * @brief Namespace que contém os símbolos das cartas do baralho.
 * 
 * Implementa os símbolos nas cartas do baralho, como naipes e valores.
*/
namespace Simbolo {

    /**
     * 
     * @brief Representa os naipes do baralho como wchars.
     *    Espadas = ''                           
     *    Ouros = ''                             
     *    Paus = ''                              
     *    Copas = ''                             
     */
    enum class Naipe : char {
        ESPADAS = 'E',
        OUROS = 'O',
        PAUS = 'P',
        COPAS = 'C'
    };

    /**
     * @brief Array que guarda todos os naipes.
     */
    static const Naipe todos_naipes[] = {
        Naipe::ESPADAS,
        Naipe::OUROS,
        Naipe::PAUS,
        Naipe::COPAS
    };

    /**
     * @brief Representa os valores do baralho como inteiros.
     *      As cartas de Ás à rei são representadas pelos valores de 1 à 13 respectivamente.
     */
    enum class Valor : int {
        AS = 1,
        DOIS,
        TRES,
        QUATRO,
        CINCO,
        SEIS,
        SETE,
        OITO,
        NOVE,
        DEZ,
        VALETE,
        DAMA,
        REI
    };

    /**
     * @brief Array que guarda todos os valores.
     */
    static const Valor todos_valores[] = {
        Valor::AS,
        Valor::DOIS,
        Valor::TRES,
        Valor::QUATRO,
        Valor::CINCO,
        Valor::SEIS,
        Valor::SETE,
        Valor::OITO,
        Valor::NOVE,
        Valor::DEZ,
        Valor::VALETE,
        Valor::DAMA,
        Valor::REI
    };
}

#endif