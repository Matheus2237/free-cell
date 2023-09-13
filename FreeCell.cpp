/**
 * @file FreeCell.cpp
 * @brief // TODO: escrever brief do projeto
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

int main() {
    Engine engine(Mesa(Baralho().embaralhar().getCartas()));
    engine.iniciaJogo();
    while(!engine.ganhou())
        engine.jogaProximaRodada();
    engine.finalizaJogo();
}