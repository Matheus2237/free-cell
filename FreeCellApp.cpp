#include "include/Baralho.h"
#include "include/Estrutura.h"
#include "include/FreeCellEngine.h"

int main() {
    // * Iniciar jogo
    FreeCellEngine engine(Estrutura(Baralho().embaralhar().getCartas()));
    while(!engine.ganhou())
        engine.jogaProximaRodada();
    // * Finalizar jogo
}