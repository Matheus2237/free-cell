#ifndef FREE_CELL_GUI_H
#define FREE_CELL_GUI_H

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

    [[deprecated("Método não implementado.")]]
    unsigned short int leColunaInicial();

    [[deprecated("Método não implementado.")]]
    unsigned short int leColunaFinal(unsigned short int colunaInicial);

private:
    
    [[deprecated("Método não implementado.")]]
    unsigned short int leColuna();
};

#endif