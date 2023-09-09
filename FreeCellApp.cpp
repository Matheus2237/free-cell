#include "include/FreeCellEngine.h"
#include "include/Baralho.h"
#include "include/Estrutura.h"

int main() {
    FreeCellEngine engine(Estrutura(Baralho().embaralhar().getCartas()));
    while(!engine.ganhou())
        engine.jogaProximaRodada();
}