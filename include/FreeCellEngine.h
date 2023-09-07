#ifndef FREE_CELL_ENGINE_H
#define FREE_CELL_ENGINE_H
#include "Estrutura.h"
#include "FreeCellGui.h"

// TODO: Encontrar um melhor nome para a classe
class FreeCellEngine {
private:
    bool jogoGanho;
    Estrutura estrutura;
    FreeCellGui interfaceGrafica;

public:

    /**
     * @brief Constrói um novo objeto Free Cell Engine.
     * 
     * @param estrutura Estrutura que contém as cartas do jogo.
     */
    FreeCellEngine(const Estrutura& estrutura);

    /**
     * @brief Destrói o objeto Free Cell Engine.
     * 
     */
    ~FreeCellEngine() = default;
    
    /**
     * @brief Verifica se o jogo foi ganho. O jogo só é ganho quando a carta do topo
     *  de todos os naipes for um rei (K).
     * 
     * @return true Se o jogo tiver ganho.
     * @return false Se o jogo não estiver ganho.
     */
    bool ganhou() const;

    /**
     * @brief Executa mais uma rodada do jogo. Em uma rodada, é exibido na tela o estado atual
     *  das cartas na mesa, lida a póxima jogada do usuário e, se for válida, realizada a
     *  movimentação desejada.s
     * 
     */
    void jogaProximaRodada();

private:

    /**
     * @brief Realiza uma busca nas pilhas de saída verificando se todas as cartas do
     *  topo são reis (K). Caso todas sejam, o jogo acabou e o atributo jogoGanho é alterado para true.
     * 
     */
    [[deprecated("Método não implementado")]]
    void verificaSeGanhou();
};

#endif