#include "../include/Baralho.h"
#include "../include/Estrutura.h"
#include "../include/verificacao/Verificacao.h"
#include "../include/verificacao/VerificacaoFactory.h"

int main() {
    Baralho baralho;
    baralho.embaralhar();
    Estrutura estrutura(baralho.getCartas());
    Verificacao* verificacao;
    
    verificacao = VerificacaoFactory::criaVerificacao(0);
    verificacao->podeMovimentar(7, 0);
    delete verificacao;

    verificacao = VerificacaoFactory::criaVerificacao(3);
    verificacao->podeMovimentar(6, 3);
    delete verificacao;

    verificacao = VerificacaoFactory::criaVerificacao(7);
    verificacao->podeMovimentar(6, 7);
    delete verificacao;
}