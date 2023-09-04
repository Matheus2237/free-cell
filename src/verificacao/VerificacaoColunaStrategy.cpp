#include "../../include/verificacao/VerificacaoColunaStrategy.h"
#include <iostream>

// TODO: Reimplementar regra
bool VerificacaoColunaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal) {
    std::cout << "Verificacao Coluna Strategy" << std::endl;
    return true;
}

bool VerificacaoColunaStrategy::corDiferente(Carta cartaMovimentacao, Carta cartaComparacao){

    switch(cartaMovimentacao.getNaipe()){
        case Simbolo::Naipe::ESPADAS:
        case Simbolo::Naipe::PAUS:
            return cartaComparacao.getNaipe() == Simbolo::Naipe::COPAS || 
                cartaComparacao.getNaipe() == Simbolo::Naipe::OUROS;
        case Simbolo::Naipe::COPAS:
        case Simbolo::Naipe::OUROS:
            return cartaComparacao.getNaipe() == Simbolo::Naipe::ESPADAS ||
                cartaComparacao.getNaipe() == Simbolo::Naipe::PAUS;
    }
}

bool VerificacaoColunaStrategy::valorImediatamenteMenor(Carta cartaMovimentacao, Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) + 1 == static_cast<int>(cartaComparacao.getValor());  
}