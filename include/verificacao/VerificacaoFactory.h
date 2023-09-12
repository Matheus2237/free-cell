/**
 * @file VerificacaoFactory.h
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

#ifndef VERIFICACAO_FACTORY_H
#define VERIFICACAO_FACTORY_H
#include "Verificacao.h"

/**
 * @brief Classe responsável por instanciar os objetos de verificação.
 * 
 * Implementa o design pattern Factory. Esta classe é responsável por criar um objeto
 * de verificação de movimentação com base no destino de onde a carta será movimentada.
 * É uma maneira conveniente de instanciar a classe que implementa a regra apropriada para
 * realizar a verificação de permissão de movimentação para a coluna desejada.
 * 
 */
class VerificacaoFactory {
public:

    /**
     * @brief Cria um objeto que implementa a regra de verificação correta para movimentação.
     *  A regra de verificação se baseia na coluna de destino e nas cartas que se deseja movimentar
     *  e de topo da coluna.
     * 
     * @param colunaFinal Coluna de destino da movimentação.
     * @return Verificacao* O objeto que implementa a regra de verificação.
     */
    static Verificacao* criaVerificacao(unsigned short int colunaFinal);

private:

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
};

#endif