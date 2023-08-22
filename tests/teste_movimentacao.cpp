#include "../include/Carta.h"
#include "../include/Baralho.h"

class Estrutura {
private:
    Carta cartas[52];

public:
    Estrutura(const Carta cartas[52]);
    void movimenta(int inicial, int final);
};


int main() {
    Baralho baralho();
    Estrutura estrutura(baralho.getCartas());
}