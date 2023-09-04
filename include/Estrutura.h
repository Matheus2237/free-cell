#ifndef ESTRUTURA_H
#define ESTRUTURA_H
#include "Baralho.h"
#include "Carta.h"

// TODO: Encontrar um melhor nome para a classe
class Estrutura {
private:
    Carta* cartas;

public:

    /**
     * @brief Constrói um novo objeto Estrutura.
     * 
     */
    Estrutura() = default;

    /**
     * @brief Constrói um novo objeto Estrutura.
     * 
     * @param cartas Ponteiro para o vetor de cartas a comporem o jogo.
     */
    Estrutura(Carta* cartas);

    /**
     * @brief Destrói o objeto Estrutura.
     * 
     */
    ~Estrutura() = default;

    /**
     * @brief Movimenta uma carta de uma coluna para outra.
     * 
     * @param colunaInicial Coluna inicial.
     * @param colunaFinal Coluna final.
     */
    void movimenta(unsigned int colunaInicial, unsigned int colunaFinal);

    /**
     * @brief Encontra a última carta de uma coluna.
     * 
     * @param coluna Coluna onde será realizada a busca.
     * @return unsigned int Posição no vetor de cartas da carta encontrada.
    */
    unsigned int encontraUltimaCartaDaColuna(unsigned int coluna) const;

    /**
     * @brief Retorna o vetor de cartas.
    */
    Carta* getCartas() const;

private:

    /**
     * @brief Atribui os valores iniciais das colunas nas cartas.
     * 
     */
    [[deprecated("Método deverá ser refeito de maneira melhor")]]
    void distribuiEmColunas();
};

#endif