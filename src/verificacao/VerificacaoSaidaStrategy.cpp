#include "../../include/verificacao/VerificacaoSaidaStrategy.h"

// TODO: Reimplementar regra
bool VerificacaoSaidaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) {
    
    Carta* cartas = estrutura.getCartas();
    Carta cartaMovimentacao = cartas[estrutura.encontraUltimaCartaDaColuna(colunaInicial)];
    Carta cartaComparacao = cartas[estrutura.encontraUltimaCartaDaColuna(colunaFinal)];

    if(estrutura.encontraUltimaCartaDaColuna(colunaFinal) == COLUNA_VAZIA){
        return true;
    }else{
        return this->valorImediatamenteMaior(cartaMovimentacao, cartaComparacao) && 
            static_cast<int>(cartaMovimentacao.getNaipe()) == 
            static_cast<int>(estrutura.encontraUltimaCartaSaida(cartaMovimentacao.getNaipe()));
    }
}

std::string VerificacaoSaidaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}

bool VerificacaoSaidaStrategy::valorImediatamenteMaior(const Carta cartaMovimentacao, const Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) - 1 == static_cast<int>(cartaComparacao.getValor());
}