#include "include/FreeCellEngine.h"

int main() {
    FreeCellEngine engine;
    while(!engine.ganhou())
        engine.jogaProximaRodada();
}