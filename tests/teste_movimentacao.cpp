#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/FreeCellGui.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Mesa estrutura(baralho.getCartas());
    FreeCellGui freeCellGui;
    freeCellGui.imprimeCartas(estrutura.getCartas());
    
    estrutura.movimenta(6, 7); 
    freeCellGui.imprimeCartas(estrutura.getCartas());
    
    estrutura.movimenta(5, 8);
    freeCellGui.imprimeCartas(estrutura.getCartas());
    
    estrutura.movimenta(6, 9);
    freeCellGui.imprimeCartas(estrutura.getCartas());

    estrutura.movimenta(9, 8);
    freeCellGui.imprimeCartas(estrutura.getCartas());

    estrutura.movimenta(7, 6);
    freeCellGui.imprimeCartas(estrutura.getCartas());
}