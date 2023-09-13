#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/FreeCellEngine.h"

void setUp(Mesa& estrutura) {
    for (int i = 0; i < TAMANHO_BARALHO; i++) {
        if (estrutura.getCartas()[i].getValor() != Simbolo::Valor::REI) {
            estrutura.getCartas()[i].setColuna(0);
        }
    }
    int reisMovidos = 0;
    while (reisMovidos < 4) {
        for (int i = 0; i < TAMANHO_BARALHO; i++) {
            if (estrutura.getCartas()[i].getValor() == Simbolo::Valor::REI) {
                Carta carta = estrutura.getCartas()[i];
                for (int j = i; j < TAMANHO_BARALHO-1; j++)
                    estrutura.getCartas()[j] = estrutura.getCartas()[j+1];
                estrutura.getCartas()[TAMANHO_BARALHO-1] = carta;
                break;
            }
        
        }
        reisMovidos++;
    }
}

int main() {
    Baralho baralho;
    Mesa estrutura(baralho.getCartas());
    setUp(estrutura);
    Engine engine(estrutura);

    engine.iniciaJogo();
    while (!engine.ganhou()) {
        engine.jogaProximaRodada();
    }
    engine.finalizaJogo();
}