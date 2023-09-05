#include <iostream>
#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/FreeCellGui.h"

int main(){
    Baralho bar;
    bar.embaralhar();
    Estrutura estr(bar.getCartas());
    FreeCellGui gui;

    gui.imprimeRegras();
    gui.imprimeLinhas(estr.getCartas());
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    gui.imprimeLinhas(estr.getCartas());
    
}