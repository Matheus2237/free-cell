#ifndef FREE_CELL_GUI_H
#define FREE_CELL_GUI_H
#define TAMANHO_BARALHO 52
#define CLEAR_LINE std::cout << "\x1b[1A\x1b[K"
#include "Carta.h"
#include "Estrutura.h"
#include <string>

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
    unsigned short int leColunaInicial(const Estrutura& estrutura);

    [[deprecated("Método não implementado.")]]
    unsigned short int leColunaFinal(unsigned short int colunaInicial);

private:
    
    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna válida,
     *  ou seja, um valor numérico inteiro que compreende de 0 a 12.
     * 
     * @param mensagemLeitura Mensagem a ser exibida para solicitar a entrada de dados.
     * @return unsigned short int Valor da coluna desejada pelo usuário.
     */
    unsigned short int leColuna(const std::string mensagemLeitura);

    /**
     * @brief Verifica se dada string contém apenas caracteres numéricos.
     * 
     * @param colunaString String a ser verificada.
     * @return true se tiver apenas caracteres numéricos.
     * @return false se tiver no mínimo um caracter não numérico.
     */
    bool somenteNumeros(std::string colunaString);
};

#endif