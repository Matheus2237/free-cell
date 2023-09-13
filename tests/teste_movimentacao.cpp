#include "../include/Baralho.h"
#include "../include/Mesa.h"
#include "../include/InterfaceDeUsuario.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Mesa mesa(baralho.getCartas());
    InterfaceDeUsuario::imprimeCartas(mesa);
    
    mesa.movimenta(6, 7); 
    InterfaceDeUsuario::imprimeCartas(mesa);
    
    mesa.movimenta(5, 8);
    InterfaceDeUsuario::imprimeCartas(mesa);
    
    mesa.movimenta(6, 9);
    InterfaceDeUsuario::imprimeCartas(mesa);

    mesa.movimenta(9, 8);
    InterfaceDeUsuario::imprimeCartas(mesa);

    mesa.movimenta(7, 6);
    InterfaceDeUsuario::imprimeCartas(mesa);
}