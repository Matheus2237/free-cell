#ifndef VERIFICACAO_FACTORY_H
#define VERIFICACAO_FACTORY_H
#include "Verificacao.h"

class VerificacaoFactory {
public:

    /**
     * @deprecated Construtor padrão removido.
     * 
     */
    VerificacaoFactory() = delete;

    /**
     * @deprecated Destrutor removido.
     * 
     */
    ~VerificacaoFactory() = delete;

    /**
     * @brief Cria um objeto que implementa a regra de verificação correta para movimentação.
     *  A regra de verificação se baseia na coluna de destino e nas cartas que se deseja movimentar
     *  e de topo da coluna.
     * 
     * @param colunaFinal Coluna de destino da movimentação.
     * @return Verificacao* O objeto que implementa a regra de verificação.
     */
    static Verificacao* criaVerificacao(unsigned short int colunaFinal);
};

#endif