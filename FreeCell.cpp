/**
 * @file FreeCell.cpp
 * 
 * @brief Trabalho de Estrutura De Dados - 4º Bimestre
 *  Implementação do jogo Free Cell em C++.
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

#include "include/Baralho.h"
#include "include/Mesa.h"
#include "include/Engine.h"
#include "include/InterfaceDeUsuario.h"

int main() {
    InterfaceDeUsuario::iniciaJogo();
    do
        Engine::jogaPartida();
    while (InterfaceDeUsuario::questionaNovaPartida());
    InterfaceDeUsuario::encerraJogo();
}