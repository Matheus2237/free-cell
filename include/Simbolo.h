#ifndef SIMBOLO_H
#define SIMBOLO_H
#define QTDE_NAIPES 4
#define QTDE_VALORES 13
#include <iostream>
#include <locale.h>
#include <wchar.h>

namespace Simbolo {

    /**
     * 
     * @brief Representa os naipes do baralho como wchars.
     *    Espadas = ''                           
     *    Ouros = ''                             
     *    Paus = ''                              
     *    Copas = ''                             
     */
    enum class Naipe : wchar_t {
        ESPADAS = L'\u2660',
        OUROS = L'\u2666',
        PAUS = L'\u2663',
        COPAS = L'\u2665'
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