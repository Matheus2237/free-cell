/**
 * @file FreeCellGui.h
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

#ifndef FREE_CELL_GUI_H
#define FREE_CELL_GUI_H
#define TAMANHO_BARALHO 52 /// TAMANHO TOTAL DO BARALHO
#define CLEAR_ALL std::cout << "\x1B[2J\x1B[H" /// Comando ANSI para limpar todo o terminal.
#define CLEAR_LINE std::cout << "\x1b[1A\x1b[K" /// Comando ANSI para limpar a linha acima da posição do cursor.
#define CARTA_VAZIA "        " /// Representa a formatação do texto de carta vazia para impressão.
#define FREECELL_VAZIA std::cout << " [   ] " 
#include "Carta.h"
#include "Estrutura.h"
#include <string>

// TODO: Implementar @brief da classe.
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
    void imprimeCartas(Estrutura &estrutura);

    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna inicial válida.
     *  Para que seja válida, ela deve ser um número inteiro entre 1 a 12 e não deve
     *  ser o valor de uma coluna vazia.
     * 
     * @param estrutura Estrutura que contém as cartas do jogo.
     * @param limpaErroPrimeiraLeitura Determina se deve limpar a linha de erro acima da linha de leitura.
     * @return unsigned short int Valor da coluna inicial.
     */
    unsigned short int leColunaInicial(const Estrutura& estrutura,
        bool limpaErroPrimeiraLeitura);

    /**
     * @brief Lê do mecanismo de entrada padrão o valor de uma coluna final válida. 
     *  Para que seja válida, ela deve ser um numero inteiro entre 0 a 12 e não deve 
     *  ser igual ao valor da coluna inicial. 
     * 
     * @param colunaInicial Valor da coluna inicial para ser usada na verificação de movimentação.
     * @return unsigned short int Valor da coluna final.
     */
    unsigned short int leColunaFinal(unsigned short int colunaInicial);

    /**
     * @brief Limpa as linhas de entrada para exibir a mensagem de erro quando uma
     *  movimentação é proibida pelas regras do jogo.
     * 
     * @param mensagemErro Mensagem de erro a ser impressa.
     */
    void trataMovimentacaoProibida(const std::string mensagemErro) const;

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
     * @param cartas Vetor que contém as cartas do jogo.
     */
    void imprimeCabecalho(Estrutura &estrutura);

    /**
     * @brief Imprime as colunas do jogo que deve ter suas cartas movidas para a saída.
     * 
     * @param cartas Vetor que contém as cartas do jogo.
     */
    void imprimeColunas(Estrutura &estrutura);

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

    /**
     * @brief Limpa a última linha escrita do terminal e imprime a mensagem de erro.
     * 
     * @param mensagemErro Mensagem informando erro a ser exibida no terminal.
     */
    void trataLinhaErro(const std::string mensagemErro);

    /**
     * @brief Reformula a linha onde é solicitada a entrada pelo usuário. Após  
     *  limpar a linha do terminal, é impresso na tela a coluna e seu valor digitado apenas.
     * 
     * @param mensagemExibicao Mensagem a ser exibida após limpeza. 
     * @param coluna Coluna digitada pelo usuŕio a ser exibida.
     */
    void exibeEntrada(const std::string mensagemExibicao, const unsigned short int coluna);

    /**
     * @brief Busca dentro da estrutura uma carta em uma determinada posição da 
     *  sua coluna de jogo.
     * 
     * @param cartas Vetor de cartas.
     * @param pos Posição da carta na coluna do jogo.
     * @param col Coluna que a carta se encontra.
     * @return int Posição no vetor da determinada carta.
     */
    int buscaCarta(Carta* cartas, int pos, int col);

    /**
     * @brief Encontra qual coluna do jogo tem a maior quantidade de cartas.
     * 
     * @param cartas Vetor de cartas.
     * @return int Coluna que possui a maior quantidade de cartas.
     */
    int maiorColuna(Carta* cartas);

    /**
     * @brief Trata os possíveis erros de lógica que podem acontecer na leitura da coluna inicial.
     *  São estes os erros: tentar mover a partir da pilha de saídas e tentar mover de uma pilha vazia.
     *  Em caso de falha, imprime o motivo de erro na saída padrão.
     * 
     * @param colunaInicial Coluna de onde o usuário deseja retirar a carta.
     * @param estrutura Estrutura que guarda as cartas durante o jogo.
     * @param colunaValida Flag que determina quando a movimentação parte de uma coluna inicial válida.
     */
    void trataErrosLeituraColunaInicial(const unsigned short int colunaInicial, 
        const Estrutura& estrutura, bool& colunaValida);
};

#endif