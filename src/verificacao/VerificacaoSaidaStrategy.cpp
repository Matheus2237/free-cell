/**
 * @file VerificacaoSaidaStrategy.cpp
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../include/verificacao/VerificacaoSaidaStrategy.h"

bool VerificacaoSaidaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Mesa& mesa) {
    
    Carta* cartas = mesa.getCartas();
    Carta cartaMovimentacao = cartas[mesa.encontraUltimaCartaDaColuna(colunaInicial)];
    Carta cartaComparacao = cartas[mesa.encontraUltimaCartaSaida(cartaMovimentacao.getNaipe())];

    return cartaMovimentacao.getValor() == Simbolo::Valor::AS ||
        this->valorImediatamenteMaior(cartaMovimentacao, cartaComparacao);
}

std::string VerificacaoSaidaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}

bool VerificacaoSaidaStrategy::valorImediatamenteMaior(const Carta cartaMovimentacao, const Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) - 1 == static_cast<int>(cartaComparacao.getValor());
}