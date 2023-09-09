#include "../../include/verificacao/VerificacaoSaidaStrategy.h"

bool VerificacaoSaidaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) {
    
    Carta* cartas = estrutura.getCartas();
    Carta cartaMovimentacao = cartas[estrutura.encontraUltimaCartaDaColuna(colunaInicial)];
    Carta cartaComparacao = cartas[estrutura.encontraUltimaCartaSaida(cartaMovimentacao.getNaipe())];

    return cartaMovimentacao.getValor() == Simbolo::Valor::AS ||
        this->valorImediatamenteMaior(cartaMovimentacao, cartaComparacao);
}

std::string VerificacaoSaidaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}

bool VerificacaoSaidaStrategy::valorImediatamenteMaior(const Carta cartaMovimentacao, const Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) - 1 == static_cast<int>(cartaComparacao.getValor());
}