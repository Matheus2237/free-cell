/**
 * @file Engine.cpp
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

#include "../include/Engine.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"
#include "../include/InterfaceDeUsuario.h"
#include "../include/MovimentacaoIndevidaException.h"

Engine::Engine(const Mesa& mesa):
    situacaoDaPartida(StatusPartida::EM_ANDAMENTO),
    mesa(mesa)
{}

void Engine::jogaPartida() {
    Engine engine(Mesa(Baralho().embaralhar().getCartas()));
    while(engine.situacaoDaPartida == StatusPartida::EM_ANDAMENTO)
        engine.jogaProximaRodada();
    engine.finalizaPartida();
}

void Engine::jogaProximaRodada() {
    InterfaceDeUsuario::imprimeCartas(mesa);
    try {
        unsigned short int colunaInicial = InterfaceDeUsuario::leColunaInicial(this->mesa);
        unsigned short int colunaFinal = InterfaceDeUsuario::leColunaFinal(colunaInicial);
        Verificacao* verificacao = VerificacaoFactory::criaVerificacao(colunaFinal);
        if (verificacao->podeMovimentar(colunaInicial, colunaFinal, this->mesa)) {
            this->mesa.movimenta(colunaInicial, colunaFinal);
            this->situacaoDaPartida = this->verificaAndamentoJogo(); 
        } else
            InterfaceDeUsuario::imprimeMotivoErro(verificacao->getMensagemErro().c_str());
        delete verificacao;
    } catch(MovimentacaoIndevidaException& mie) {
        InterfaceDeUsuario::imprimeMotivoErro(mie.what());
    }
}

Engine::StatusPartida Engine::verificaAndamentoJogo() {
    if (this->verificaSePerdeu())
        return StatusPartida::DERROTA;
    else if (this->verificaSeGanhou())
        return StatusPartida::VITORIA;
    else
        return StatusPartida::EM_ANDAMENTO;
}

bool Engine::verificaSePerdeu() {
    return mesa.checaMovimentacoesPossiveis() == 0;
}

bool Engine::verificaSeGanhou() {
    for (int naipe = 0; naipe < Simbolo::QTDE_NAIPES; naipe++)
        if (this->mesa.getCartas()[this->mesa.encontraUltimaCartaSaida(Simbolo::todos_naipes[naipe])]
                .getValor() != Simbolo::Valor::REI)
            return false;
    return true;
}

void Engine::finalizaPartida() {
    if (this->situacaoDaPartida == StatusPartida::VITORIA)
        InterfaceDeUsuario::exibeTrofeu();
    else if (this->situacaoDaPartida == StatusPartida::DERROTA)
        InterfaceDeUsuario::exibeFailWhale();
}