#ifndef FREE_CELL_GUI_H
#define FREE_CELL_GUI_H
#define TAMANHO_BARALHO 52
#include "../include/Carta.h"

class FreeCellGui {

public:

    /**
     * @brief Constrói um novo objeto Free Cell Graphical User Interface.
     * 
     */
    FreeCellGui() = default;

    /**
     * @brief Destrói o objeto Free Cell Graphical User Interface.
     * 
     */
    ~FreeCellGui() = default;

    /**
     * @brief Imprime a estrutura de cartas do jogo.
     * 
     * @param cartas Ponteiro para vetor de cartas da estrutura.
     */
    void imprimeCartas(Carta* cartas) const;

    [[deprecated("Método não implementado.")]]
    unsigned short int leColunaInicial();

    [[deprecated("Método não implementado.")]]
    unsigned short int leColunaFinal(unsigned short int colunaInicial);

private:
    
    [[deprecated("Método não implementado.")]]
    unsigned short int leColuna();
};

#endif