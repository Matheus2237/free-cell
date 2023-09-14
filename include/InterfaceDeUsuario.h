/**
 * @file InterfaceDeUsuario.h
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

#ifndef INTERFACE_DE_USUARIO_H
#define INTERFACE_DE_USUARIO_H
#define CLEAR_ALL std::cout << "\x1B[2J\x1B[H" /// Comando ANSI para limpar todo o terminal.
#define CLEAR_LINE std::cout << "\x1b[1A\x1b[K" /// Comando ANSI para limpar a linha acima da posição do cursor.
#define FREECELL_VAZIA std::cout << " [   ] " /// Comando para impressão de um template de free cell vazia
#define SAIDA_COPAS_VAZIA std::cout << " [ C ] "; /// Comando para impressão do placeholder da saída do naipe Copas.
#define SAIDA_PAUS_VAZIA std::cout << " [ P ] "; /// Comando para impressão do placeholder da saída do naipe Paus.
#define SAIDA_OUROS_VAZIA std::cout << " [ O ] "; /// Comando para impressão do placeholder da saída do naipe Ouros.
#define SAIDA_ESPADAS_VAZIA std::cout << " [ E ] "; /// Comando para impressão do placeholder da saída do naipe Espadas.

#include "Carta.h"
#include "Mesa.h"
#include "MovimentacaoIndevidaException.h"
#include <string>

const std::string CARTA_VAZIA = "       "; /// Representa a formatação do texto de carta vazia para impressão.

/**
 * @brief Classe que implementa a interface gráfica do jogo.
 * 
 * Implementa a interface gráfica do jogo, com métodos para impressão da mesa
 * de cartas e leitura de entrada do usuário.
 * 
 */
class InterfaceDeUsuario {
public:

    /**
     * @deprecated Construtor padrão removido.
     * 
     */
    InterfaceDeUsuario() = delete;

    /**
     * @brief Destrutor removido.
     * 
     */
    ~InterfaceDeUsuario() = delete;

    /**
     * @brief Imprime a mesa de cartas do jogo.
     * 
     * @param mesa Mesa que guarda as cartas durante o jogo.
     */
    static void imprimeCartas(Mesa &mesa);

    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna inicial válida.
     *  Para que seja válida, ela deve ser um número inteiro entre 1 a 12 e não deve
     *  ser o valor de uma coluna vazia.
     * 
     * @param mesa Mesa que contém as cartas do jogo.
     * @return unsigned short int Valor da coluna inicial.
     */
    static unsigned short int leColunaInicial(const Mesa& mesa);

    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna final válida. 
     *  Para que seja válida, ela deve ser um numero inteiro entre 0 a 12 e não deve 
     *  ser igual ao valor da coluna inicial. 
     * 
     * @param colunaInicial Valor da coluna inicial para ser usada na verificação de movimentação.
     * @return unsigned short int Valor da coluna final.
     */
    static unsigned short int leColunaFinal(unsigned short int colunaInicial);

    static void imprimeMotivoErro(const char* mensagemDeErro);

    /**
     * @brief Imprime o título do jogo e aguarda um tempo para visualização.
     * 
     */
    static void exibeTitulo();

    /**
     * @brief Imprime os créditos aos desenvolvedores e aguarda um tempo para visualização.
     * 
     */
    static void exibeDevs();

    /**
     * @brief Imprime as regras na tela se o usuário desejar e aguarda que o usuário pare a exibição.
     * 
     */
    static void exibeRegras();

    /**
     * @brief Imprime o troféu quando o usuário ganhar o jogo :)
     * 
     */
    static void exibeTrofeu();

private:
    
    /**
     * @brief Imprime as regras no início do jogo se o usuário desejar.
     * 
     */
    static void imprimeRegras();

    /**
     * @brief Imprime o cabeçalho da mesa de jogo. O cabeçalho contém as free cells e as saídas.
     * 
     * @param mesa Mesa que guarda as cartas durante o jogo.
     */
    static void imprimeCabecalho(Mesa &mesa);

    /**
     * @brief Imprime as colunas do jogo que deve ter suas cartas movidas para a saída.
     * 
     * @param mesa Mesa que guarda as cartas durante o jogo.
     */
    static void imprimeColunas(Mesa &mesa);

    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna válida,
     *  ou seja, um valor numérico inteiro que compreende de 0 a 12.
     * 
     * @param mensagemLeitura Mensagem a ser exibida para solicitar a entrada de dados.
     * @return unsigned short int Valor da coluna desejada pelo usuário.
     */
    static unsigned short int leColuna(const std::string mensagemLeitura);

    /**
     * @brief Verifica se dada string contém apenas caracteres numéricos.
     * 
     * @param colunaString String a ser verificada.
     * @return true se tiver apenas caracteres numéricos.
     * @return false se tiver no mínimo um caracter não numérico.
     */
    static bool somenteNumeros(std::string colunaString);

    /**
     * @brief Reformula a linha onde é solicitada a entrada pelo usuário. Após  
     *  limpar a linha do terminal, é impresso na tela a coluna e seu valor digitado apenas.
     * 
     * @param mensagemExibicao Mensagem a ser exibida após limpeza. 
     * @param coluna Coluna digitada pelo usuŕio a ser exibida.
     */
    static void exibeEntrada(const std::string mensagemExibicao, const unsigned short int coluna);

    /**
     * @brief Busca dentro da mesa uma carta em uma determinada posição da 
     *  sua coluna de jogo.
     * 
     * @param cartas Vetor de cartas.
     * @param pos Posição da carta na coluna do jogo.
     * @param col Coluna que a carta se encontra.
     * @return int Posição no vetor da determinada carta.
     */
    static int buscaCarta(Carta* cartas, int pos, unsigned int col);

    /**
     * @brief Encontra qual coluna do jogo tem a maior quantidade de cartas.
     * 
     * @param cartas Vetor de cartas.
     * @return int Coluna que possui a maior quantidade de cartas.
     */
    static int maiorColuna(Carta* cartas);

    /**
     * @brief Trata os possíveis erros de lógica que podem acontecer na leitura da coluna inicial.
     *  São estes os erros: tentar mover a partir da pilha de saídas e tentar mover de uma pilha vazia.
     *  Em caso de falha, lança uma exceção a ser tratada contendo a mensagem de erro a ser impressa.
     * 
     * @param colunaInicial Coluna de onde o usuário deseja retirar a carta.
     * @param mesa Mesa que guarda as cartas durante o jogo.
     * @throw MovimentacaoIndevidaException caso ocorra alguma entrada que possui falha de lógica. 
     */
    static void trataErrosLeituraColunaInicial(const unsigned short int colunaInicial, 
        const Mesa& mesa);

    /**
     * @brief Recebe do usuario a confirmacao de que deseja prosseguir ou nao com uma acao.
     * 
     * @param std::string textoExibicao Texto a ser exibido ao solicitar a confirmação.
     * @return True caso a entrada seja "S" ou  "s".
     * @return False caso a entrada seja "N" ou "n".
     */
    static bool confirmaAcao(const std::string textoExibicao);
};

#endif