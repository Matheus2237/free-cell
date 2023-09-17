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

/**
 * @brief Classe que implementa a engine do jogo.
 * 
 * Implementa a engine do jogo, que consiste em executar as jogadas do usuário e realizar verificação
 * de vitoria ou derrota.
*/
class Engine {
private:

    /**
     * @brief Status da partida em questão. A partida pode assumit três estados: vitória quando
     *  as 52 cartas foram movimentadas para a coluna de saída; derrota quando não há mais 
     *  movimentações possíveis e em andamento enquando ainda há jogadas a serem feitas.
     * 
     */
    enum class StatusPartida {
        EM_ANDAMENTO, VITORIA, DERROTA
    };

    /**
     * @brief Atributo que determina a situação do jogo. Por padrão é em andamento,
     *  pois o jogo inicia sempre com jogadas a serem feitas. Pode assumir também
     *  tanto o valor de vitória ou de derrota, indicando que a partida deve ser
     *  finalizada pois não há mais jogadas possíveis.
     * 
     */
    StatusPartida situacaoDaPartida;

    /**
     * @brief Mesa de dados abstrata que armazena as cartas da partida, bem
     *  bem como sua posição na mesa. Também fornece métodos para interagir com
     *  a posição das cartas na mesa.
     * 
     */
    Mesa mesa;

// TODO: Deixar apenas o metodo estatico publico
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
     * @brief Cria uma nova partida de Free Cell. A partida acaba quando for 
     *  vencida ou quando não houver mais movimentações possíveis.
     * 
     */
    static void jogaPartida();

    /**
     * @brief Executa mais uma rodada do jogo. Em uma rodada, é exibido na tela o estado atual
     *  das cartas na mesa, lida a póxima jogada do usuário e, se esta for válida, realiza a
     *  movimentação desejada.
     * 
     */
    void jogaProximaRodada();

    /**
     * @brief Verifica em que situação o jogo se encontra baseando na disposição das cartas na mesa.
     * 
     * @return Engine::StatusPartida Retorna o status da partida em questão.
     */
    Engine::StatusPartida verificaAndamentoJogo();

    /**
     * @brief Finaliza a partida exibindo na tela a mensagem indicada.
     * 
     */
    void finalizaPartida();

private:
    
    /**
     * @brief Verifica se o usuário não tem mais possíveis jogadas a serem realizadas.
     * 
     * @return true Caso a condição acima seja satisfeita.
     * @return false Caso o condição acima não esteja satisfeita.
     */
    bool verificaSePerdeu();

    /**
     * @brief Realiza uma busca nas pilhas de saída verificando se todas as cartas do
     *  topo são reis (K).
     * 
     * @return true Caso a condição acima seja satisfeita.
     * @return false Caso o condição acima não esteja satisfeita.
     */
    bool verificaSeGanhou();
};

#endif