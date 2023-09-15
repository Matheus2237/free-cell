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
#include <sstream>
#include <thread>
#include <chrono>
#include <limits>


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
    for(int naipe = Simbolo::QTDE_NAIPES - 1; naipe >= 0; naipe--){
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

unsigned short int InterfaceDeUsuario::leColunaInicial(const Mesa& mesa) {
    const std::string mensagemLeitura = "Entre o valor da coluna inicial: ";
    unsigned short int colunaInicial = InterfaceDeUsuario::leColuna(mensagemLeitura);
    InterfaceDeUsuario::trataErrosLeituraColunaInicial(colunaInicial, mesa);
    InterfaceDeUsuario::exibeEntrada("Coluna incial: ", colunaInicial);
    return colunaInicial;
}

void InterfaceDeUsuario::trataErrosLeituraColunaInicial(const unsigned short int colunaInicial, 
        const Mesa& mesa) {
    if (colunaInicial == 0)
        throw MovimentacaoIndevidaException("Não pode mover carta da saída, tente novamente. ");
    else if (mesa.encontraUltimaCartaDaColuna(colunaInicial) == COLUNA_VAZIA)
        throw MovimentacaoIndevidaException("Não pode mover de uma coluna vazia, tente novamente. ");
}

unsigned short int InterfaceDeUsuario::leColunaFinal(unsigned short int colunaInicial) {
    const std::string mensagemLeitura = "Entre o valor da coluna final: ";
    unsigned short int colunaFinal = InterfaceDeUsuario::leColuna(mensagemLeitura);
    if (colunaFinal == colunaInicial)
        throw MovimentacaoIndevidaException("Não pode mover a carta para a mesma coluna, tente novamente. ");
    InterfaceDeUsuario::exibeEntrada("Coluna final: ", colunaFinal);
    return colunaFinal;
}

unsigned short int InterfaceDeUsuario::leColuna(const std::string mensagemLeitura) {
    std::string coluna;
    bool colunaValida = false;
    while(!colunaValida) {
        std::cout << mensagemLeitura;
        std::getline(std::cin, coluna);
        colunaValida = !coluna.empty() && InterfaceDeUsuario::somenteNumeros(coluna) &&
            std::stoi(coluna) >=0 && std::stoi(coluna) <= 12;
        if (!colunaValida)
            CLEAR_LINE << "Coluna invalida, tente novamente. ";
    }
    return std::stoi(coluna);
}

bool InterfaceDeUsuario::somenteNumeros(std::string colunaString) {
    for (size_t i = 0; i < colunaString.length(); i++)
        if(!isdigit(colunaString[i]))
            return false;
    return true;
}

void InterfaceDeUsuario::exibeEntrada(const std::string mensagemExibicao, const unsigned short int coluna) {
    CLEAR_LINE;
    std::cout << mensagemExibicao << coluna << std::endl;
}

void InterfaceDeUsuario::imprimeMotivoErro(const char* mensagemDeErro) {
    std::cout << std::endl;
    std::cerr << mensagemDeErro << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void InterfaceDeUsuario::imprimeRegras(){
    std::cout << "                            ********************" << std::endl
              << "                            *                  * " << std::endl
              << "                            * *REGRAS DO JOGO* * " << std::endl 
              << "                            *                  * " << std::endl
              << "                            ********************" << std::endl
              << "  _______________________________________________________________________" << std::endl
              << " / Visão geral do jogo:                                                 \\ " << std::endl  
              << " |* No canto superior esquerdo terá 4 espaços vazios(chamados também de |" << std::endl
              << " |FreeCells), onde você poderá armazenar temporariamente durante o jogo.|" << std::endl
              << " |                                                                      |" << std::endl
              << " |* No canto superior DIREITO também há 4 espaços vazios, mas neles     |" << std::endl
              << " |é onde você fará as pilhas de saida.                                  |" << std::endl
              << " |                                                                      |" << std::endl
              << " |Objetivo do jogo:                                                     |" << std::endl
              << " |* Fazer 4 pilhas de 13 cartas cada. Cada pilha deve ser feita na      |" << std::endl
              << " |ordem crescente do ás até o rei.                                      |" << std::endl
              << " |                                                                      |" << std::endl
              << " |Como jogar:                                                           |" << std::endl
              << " |Retire cartas da parte inferior de cada coluna e mova-as da seguinte  |" << std::endl
              << " |maneira:                                                              |" << std::endl
              << " |                                                                      |" << std::endl
              << " |* De uma coluna para uma célula vazia. As células vazias só podem     |" << std::endl
              << " |conter uma carta de cada vez.                                         |" << std::endl
              << " |                                                                      |" << std::endl
              << " |* De uma coluna para outra (ou de uma célula vazia para uma coluna).  |" << std::endl
              << " |As cartas devem ser colocadas na coluna em ordem sequencial           |" << std::endl
              << " |decrescente, e é necessário alternar naipes vermelhos e pretos.       |" << std::endl
              << " |                                                                      |" << std::endl
              << " |* De uma coluna para uma célula inicial. Cada pilha deve consistir de |" << std::endl
              << " \\um único naipe e começar por um ás.                                  /" << std::endl
              << "  ----------------------------------------------------------------------" << std::endl
              << "             \\    ,-^-." << std::endl
              << "              \\   !oYo!" << std::endl
              << "               \\ /./=\\.\\______" << std::endl
              << "                    ##        )\\/\\" << std::endl
              << "                     ||-----w||" << std::endl
              << "                     ||      ||" << std::endl;
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}

void InterfaceDeUsuario::exibeTitulo() {
    CLEAR_ALL;
    std::cout
        << std::endl
        << std::endl
        << "          ______                _____     _ _              " << std::endl
        << "         |  ____|              / ____|   | | |             " << std::endl
        << "         | |__ _ __ ___  ___  | |     ___| | |             " << std::endl
        << "         |  __| '__/ _ \\/ _ \\ | |    / _ \\ | |          " << std::endl
        << "         | |  | | |  __/  __/ | |___|  __/ | |             " << std::endl
        << "         |_|  |_|  \\___|\\___|  \\_____\\___|_|_|         " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void InterfaceDeUsuario::exibeDevs() {
    CLEAR_ALL;
    std::cout
        << std::endl
        << std::endl
        << std::endl
        << std::endl
        << "              Desenvolvido por:                       " << std::endl
        << "              Carlos Sérgio Fernandes Júnior          " << std::endl
        << "              Matheus Paulino Ribeiro                 " << std::endl
        << "              Nicolas Fagundes Scarpa                 " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void InterfaceDeUsuario::exibeRegras() {
    CLEAR_ALL;
    std::stringstream textoExibicao;
    std::string verifica;
    textoExibicao << std::endl << std::endl << std::endl << std::endl << std::endl
        << "         Deseja consultar as regras do jogo? [S/n] ";
    if (InterfaceDeUsuario::confirmaAcao(textoExibicao.str())) {
        CLEAR_ALL;
        InterfaceDeUsuario::imprimeRegras();
        std::string verif;
        std::cout << "Aperte enter para continuar...";
        getline(std::cin, verifica);
        if(verifica == "")
            return;
    }
}

bool InterfaceDeUsuario::confirmaAcao(const std::string textoExibicao) {
    while(true) {
        std::cout << textoExibicao;
        std::string entrada;
        getline(std::cin, entrada);
        if(entrada == "S" || entrada == "s")
            return true;
        else if(entrada == "N" || entrada == "n")
            return false;
        else
            CLEAR_ALL;
    }
}

void InterfaceDeUsuario::exibeTrofeu() {
    CLEAR_ALL;
    std::cout 
        << "                     '._==_==_=_.'          " << std::endl
        << "                     .-\\:      /-.         " << std::endl
        << "                    | (|:.     |) |         " << std::endl
        << "                     '-|:.     |-'          " << std::endl
        << "                       \\::.    /           " << std::endl
        << "                        '::. .'             " << std::endl
        << "                          ) (               " << std::endl
        << "                        _.' '._             " << std::endl
        << "                       `\"\"\"\"\"\"\"`     " << std::endl
        << "                                            " << std::endl
        << "                 Parabens! Você ganhou!      " << std::endl
        << "                                            " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
}