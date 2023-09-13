#include "../include/Baralho.h"
#include "../include/Mesa.h"
#include "../include/InterfaceDeUsuario.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Mesa mesa(baralho.getCartas());
    InterfaceDeUsuario::imprimeCartas(mesa);
}