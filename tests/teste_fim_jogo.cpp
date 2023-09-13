#include "../include/Baralho.h"
#include "../include/Mesa.h"
#include "../include/InterfaceDeUsuario.h"
#include "../include/Engine.h"

void setUp(Mesa& mesa) {
    for (int i = 0; i < TAMANHO_BARALHO; i++) {
        if (mesa.getCartas()[i].getValor() != Simbolo::Valor::REI) {
            mesa.getCartas()[i].setColuna(0);
        }
    }
    int reisMovidos = 0;
    while (reisMovidos < 4) {
        for (int i = 0; i < TAMANHO_BARALHO; i++) {
            if (mesa.getCartas()[i].getValor() == Simbolo::Valor::REI) {
                Carta carta = mesa.getCartas()[i];
                for (int j = i; j < TAMANHO_BARALHO-1; j++)
                    mesa.getCartas()[j] = mesa.getCartas()[j+1];
                mesa.getCartas()[TAMANHO_BARALHO-1] = carta;
                break;
            }
        
        }
        reisMovidos++;
    }
}

int main() {
    Baralho baralho;
    Mesa mesa(baralho.getCartas());
    setUp(mesa);
    Engine engine(mesa);

    engine.iniciaJogo();
    while (!engine.ganhou()) {
        engine.jogaProximaRodada();
    }
    engine.finalizaJogo();
}