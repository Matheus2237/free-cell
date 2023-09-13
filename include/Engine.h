/**
 * @file Engine.h
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

#ifndef ENGINE_H
#define ENGINE_H
#include "Mesa.h"
#include "FreeCellGui.h"

/**
 * @brief Classe que implementa a engine do jogo.
 * 
 * Implementa a engine do jogo, que consiste em executar as jogadas do usuário e realizar verificação
 * de vitoria ou derrota.
*/
class Engine {
private:

    /**
     * @brief Flag que determina se o jogo está ganho ou não. Por padrão é falsa,
     *  significando que o jogo ainda não está terminado. Quando o valor true for
     *  atribuido, então o jogo passa a ter o estado de finalizado.
     * 
     */
    bool jogoGanho;

    /**
     * @brief Mesa de dados abstrata que armazena as cartas da partida, bem
     *  bem como sua posição na mesa. Também fornece métodos para interagir com
     *  a posição das cartas na mesa.
     * 
     */
    Mesa mesa;

public:

    /**
     * @brief Constrói um novo objeto Engine.
     * 
     * @param mesa Mesa que contém as cartas do jogo.
     */
    Engine(const Mesa& mesa);

    /**
     * @brief Destrói o objeto Engine.
     * 
     */
    ~Engine() = default;
    
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

    /**
     * @brief Inicia o jogo exibindo o título e o nome da equipe de desenvolvimento.
     * 
     */
    void iniciaJogo();

    /**
     * @brief Finaliza o jogo exibindo na tela o troféu ao vencedor.
     * 
     */
    void finalizaJogo();

private:

    /**
     * @brief Realiza uma busca nas pilhas de saída verificando se todas as cartas do
     *  topo são reis (K). Caso todas sejam, o atributo jogoGanho é alterado para true.
     * 
     */
    void verificaSeGanhou();
};

#endif