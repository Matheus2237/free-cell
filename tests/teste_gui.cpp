#include <iostream>
#include "../include/Baralho.h"
#include "../include/Mesa.h"
#include "../include/InterfaceDeUsuario.h"

int main(){
    Baralho bar;
    bar.embaralhar();
    Mesa estr(bar.getCartas());

    InterfaceDeUsuario::imprimeCartas(estr);
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    estr.movimenta(5, 12);
    estr.movimenta(12, 1);
    InterfaceDeUsuario::imprimeCartas(estr);
    estr.movimenta(1, 5);
    InterfaceDeUsuario::imprimeCartas(estr);
    
}