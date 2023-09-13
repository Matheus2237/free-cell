/**
 * @file InterfaceDeUsuario.cpp
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

#include "../include/InterfaceDeUsuario.h"
#include "../include/Simbolo.h"
#include <iostream>
#include <thread>
#include <chrono>


void InterfaceDeUsuario::imprimeCartas(Mesa &mesa) {
    CLEAR_ALL;
    InterfaceDeUsuario::imprimeCabecalho(mesa);
    InterfaceDeUsuario::imprimeColunas(mesa);
}

void InterfaceDeUsuario::imprimeCabecalho(Mesa &mesa){
    for(int FreeCell = 9; FreeCell <= 12; FreeCell++){
        if(mesa.encontraUltimaCartaDaColuna(FreeCell) == COLUNA_VAZIA)
            FREECELL_VAZIA;
        else
            std::cout << mesa.getCartas()[mesa.encontraUltimaCartaDaColuna(FreeCell)];
    }
    for(int naipe = QTDE_NAIPES - 1; naipe >= 0; naipe--){
        if(mesa.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe]) == COLUNA_VAZIA){
            switch (naipe)
            {
            case 3:
                SAIDA_COPAS_VAZIA
            break;
            case 2:
                SAIDA_PAUS_VAZIA
            break;
            case 1:
                SAIDA_OUROS_VAZIA
            break;
            case 0:
                SAIDA_ESPADAS_VAZIA
            break;
            }
        } 
        else
        std::cout << mesa.getCartas()[mesa.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe])];
    }
    std::cout << std::endl << "   9      10     11     12                0" << std::endl;
}

void InterfaceDeUsuario::imprimeColunas(Mesa &mesa) {
    for(int linha = 0; linha <= maiorColuna(mesa.getCartas()); linha++){
        for(int coluna = 1; coluna <= 8; coluna++){
            int posicaoCarta = buscaCarta(mesa.getCartas(), linha, coluna);
            if (posicaoCarta == COLUNA_VAZIA)
                std::cout << CARTA_VAZIA;
            else
                std::cout << mesa.getCartas()[posicaoCarta];
        }
        std::cout << std::endl;        
    }
    std::cout << "   1      2      3      4      5      6      7      8" << std::endl;
    std::cout << std::endl;
}

int InterfaceDeUsuario::maiorColuna(Carta* cartas){
    int maiorColl = 0;
    for(unsigned int coluna = 1; coluna <= 8; coluna++){
        int countColl = 0;
        for(int i = TAMANHO_BARALHO-1; i >= 0; i--){
            if(cartas[i].getColuna() == coluna)
                countColl++;
        }
        if(countColl > maiorColl)
            maiorColl = countColl;
    }
    return maiorColl;
}

int InterfaceDeUsuario::buscaCarta(Carta* cartas, int pos, unsigned int col){
    int p = 0;
    for (int i = 0; i < TAMANHO_BARALHO; i++) {
        if (cartas[i].getColuna() == col) {
            if(p == pos)
                return i;
            else
                p++;    
        }
    }
    return COLUNA_VAZIA;
}

unsigned short int InterfaceDeUsuario::leColunaInicial(const Mesa& mesa,
        bool limpaErroPrimeiraLeitura) {
    const std::string mensagemLeitura = "Entre o valor da coluna inicial: ";
    unsigned short int colunaInicial;
    bool colunaValida = false;
    while (!colunaValida) {
        colunaInicial = InterfaceDeUsuario::leColuna(mensagemLeitura);
        if (limpaErroPrimeiraLeitura)
            CLEAR_LINE;
        InterfaceDeUsuario::trataErrosLeituraColunaInicial(colunaInicial, mesa, colunaValida);
    }
    InterfaceDeUsuario::exibeEntrada("Coluna incial: ", colunaInicial);
    return colunaInicial;
}

void InterfaceDeUsuario::trataErrosLeituraColunaInicial(const unsigned short int colunaInicial, 
        const Mesa& mesa, bool& colunaValida) {
    if (colunaInicial == 0)
        InterfaceDeUsuario::trataLinhaErro("Não pode mover carta da saída, tente novamente. ");
    else if (mesa.encontraUltimaCartaDaColuna(colunaInicial) == COLUNA_VAZIA)
        InterfaceDeUsuario::trataLinhaErro("Não pode movar de uma coluna vazia, tente novamente. ");
    else
        colunaValida = true;
}

unsigned short int InterfaceDeUsuario::leColunaFinal(unsigned short int colunaInicial) {
    const std::string mensagemLeitura = "Entre o valor da coluna final: ";
    unsigned short int colunaFinal;
    bool colunaValida = false;
    while (!colunaValida) {
        colunaFinal = InterfaceDeUsuario::leColuna(mensagemLeitura);
        colunaValida = colunaFinal != colunaInicial;
        if (!colunaValida)
            InterfaceDeUsuario::trataLinhaErro("Não pode mover a carta para a mesma coluna, tente novamente. ");
    }
    InterfaceDeUsuario::exibeEntrada("Coluna final: ", colunaFinal);
    return colunaFinal;
}

unsigned short int InterfaceDeUsuario::leColuna(const std::string mensagemLeitura) {
    std::string coluna;
    const std::string mensagemErro = "Coluna invalida, tente novamente. ";
    bool colunaValida = false;
    while(!colunaValida) {
        std::cout << mensagemLeitura;
        std::getline(std::cin, coluna);
        colunaValida = !coluna.empty() && InterfaceDeUsuario::somenteNumeros(coluna) &&
            std::stoi(coluna) >=0 && std::stoi(coluna) <= 12;
        if (!colunaValida)
            InterfaceDeUsuario::trataLinhaErro(mensagemErro);
    }
    return std::stoi(coluna);
}

bool InterfaceDeUsuario::somenteNumeros(std::string colunaString) {
    for (int i = 0; i < colunaString.length(); i++)
        if(!isdigit(colunaString[i]))
            return false;
    return true;
}


void InterfaceDeUsuario::trataLinhaErro(const std::string mensagemErro) {
    CLEAR_LINE;
    std::cout << mensagemErro;
}

void InterfaceDeUsuario::exibeEntrada(const std::string mensagemExibicao, const unsigned short int coluna) {
    CLEAR_LINE;
    std::cout << mensagemExibicao << coluna << std::endl;
}

void InterfaceDeUsuario::trataMovimentacaoProibida(std::string mensagemErro) {
    CLEAR_LINE;
    CLEAR_LINE;
    std::cout << mensagemErro << std::endl;
}

// TODO: Formatar texto da regra
void InterfaceDeUsuario::imprimeRegras(){
    std::cout << "O jogador fará quantos movimentos quiser, entre as pilhas que quiser, respeitando as seguintes regras: " << std::endl
              << "Para uma free cell desocupada: qualquer carta do topo de uma pilha de jogo; " << std::endl
              << "Para uma das pilhas de saída: qualquer carta de uma free cell ou do topo de uma pilha de jogo. Movimentos para uma pilha de saída " << std::endl
              << "devem ser feitos em ordem do menor para o maior, sempre de mesmo naipe. Assim, temos uma pilha de saída para cada um dos 4 " << std::endl
              << "naipes. Ases sempre podem ser movidos para uma pilha de saída vazia; " << std::endl
              << "Para o topo de uma pilha de jogo: qualquer carta de uma das free cells ou do topo de uma outra pilha de jogo. Movimentos para uma " << std::endl
              << "pilha de jogo devem ser feitos em ordem do maior para o menor, alternando a cor do naipe. Por exemplo: se o topo de uma pilha de " << std::endl
              << "jogo contém um 4 de paus (que é preto), podemos mover para o topo dessa pilha um 3 de copas ou de ouro (que são vermelhos). " << std::endl
              << "O fim do jogo é alcançado quando todas as cartas forem movidas para as pilhas de saída ou quando não há movimento que permita mais alguma " << std::endl
              << "carta ser movida para uma das pilhas de saída." << std::endl;
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
}

// ! Ajustar formatação
void InterfaceDeUsuario::exibeTitulo() {
    CLEAR_ALL;
    std::cout
        << std::endl
        << std::endl
        << std::endl
        << "           ______                _____     _ _              " << std::endl
        << "          |  ____|              / ____|   | | |             " << std::endl
        << "          | |__ _ __ ___  ___  | |     ___| | |             " << std::endl
        << "          |  __| '__/ _ \\/ _ \\ | |    / _ \\ | |          " << std::endl
        << "          | |  | | |  __/  __/ | |___|  __/ | |             " << std::endl
        << "          |_|  |_|  \\___|\\___|  \\_____\\___|_|_|         " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

// ! Ajustar formatação
void InterfaceDeUsuario::exibeDevs() {
    CLEAR_ALL;
    std::cout
        << std::endl
        << std::endl
        << std::endl
        << "          Desenvolvido por:                         " << std::endl
        << "            Carlos Sérgio Fernandes Júnior          " << std::endl
        << "            Matheus Paulino Ribeiro                 " << std::endl
        << "            Nicolas Fagundes Scarpa                 " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

// ! Ajustar formatação
void InterfaceDeUsuario::exibeRegras() {
    CLEAR_ALL;
    char le;
    std::cout << std::endl
        << std::endl
        << std::endl
        << "    Deseja consultar as regras do jogo? [S/n] ";
    std::cin >> le;
    if (le == 'S') {
        CLEAR_ALL;
        InterfaceDeUsuario::imprimeRegras();
    }
    std::cin.ignore();
}

// ! Ajustar formatação
void InterfaceDeUsuario::exibeTrofeu() {
    CLEAR_ALL;
    std::cout 
        << std::endl
        << "            '._==_==_=_.'                   " << std::endl
        << "            .-\\:      /-.                  " << std::endl
        << "           | (|:.     |) |                  " << std::endl
        << "            '-|:.     |-'                   " << std::endl
        << "              \\::.    /                    " << std::endl
        << "               '::. .'                      " << std::endl
        << "                 ) (                        " << std::endl
        << "               _.' '._                      " << std::endl
        << "              `\"\"\"\"\"\"\"`              " << std::endl
        << "                                            " << std::endl
        << "        Parabens! Voce ganhou!              " << std::endl
        << "                                            " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
}