#ifndef SIMBOLO_H
#define SIMBOLO_H

namespace Simbolo {

    /**
     * 
     * @brief Representa os naipes do baralho como chars.
     *    Espadas = 'E'                           
     *    Ouros = 'O'                             
     *    Paus = 'P'                              
     *    Copas = 'C'                             
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