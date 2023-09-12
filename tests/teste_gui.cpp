#include <iostream>
#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/FreeCellGui.h"

int main(){
    Baralho bar;
    bar.embaralhar();
    Mesa estr(bar.getCartas());
    FreeCellGui gui;

    gui.imprimeRegras();
    gui.imprimeCabecalho(estr);
    gui.imprimeCartas(estr.getCartas());
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    estr.movimenta(12, 1);
    gui.imprimeCabecalho(estr);
    gui.imprimeCartas(estr.getCartas());
    estr.movimenta(1, 5);
    gui.imprimeCabecalho(estr);
    gui.imprimeCartas(estr.getCartas());
    
}