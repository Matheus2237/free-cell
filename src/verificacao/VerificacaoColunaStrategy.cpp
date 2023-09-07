#include "../../include/verificacao/VerificacaoColunaStrategy.h"

bool VerificacaoColunaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) {    
    Carta* cartas = estrutura.getCartas();
    Carta cartaMovimentacao = cartas[estrutura.encontraUltimaCartaDaColuna(colunaInicial)];
    Carta cartaComparacao = cartas[estrutura.encontraUltimaCartaDaColuna(colunaFinal)];
    return this->corDiferente(cartaMovimentacao, cartaComparacao) &&
        this->valorImediatamenteMenor(cartaMovimentacao, cartaComparacao);
}

bool VerificacaoColunaStrategy::corDiferente(const Carta cartaMovimentacao, const Carta cartaComparacao){

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

bool VerificacaoColunaStrategy::valorImediatamenteMenor(const Carta cartaMovimentacao, const Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) + 1 == static_cast<int>(cartaComparacao.getValor());  
}

std::string VerificacaoColunaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}