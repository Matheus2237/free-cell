#include "include/FreeCellEngine.h"
#include "include/Baralho.h"
#include "include/Estrutura.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    FreeCellEngine engine(Estrutura(baralho.getCartas()));
    while(!engine.ganhou())
        engine.jogaProximaRodada();
}