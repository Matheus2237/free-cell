#ifndef VERIFICACAO_H
#define VERIFICACAO_H
#include "../Carta.h"
#include "../Estrutura.h"
#include "../FreeCellGui.h"
#include <string>

class Verificacao {
public:

    /**
     * @brief Construtor padrão para o objeto Verificação.
     * 
     */
    Verificacao() = default;

    /**
     * @brief Destrutor padrão para o objeto verificação.
     * 
     */
    ~Verificacao() = default;

    /**
     * @brief Verifica se a carta de uma coluna pode ser movimentada para uma
     *  outra coluna. O critério de permissão se baseia na coluna de destino.
     * 
     * @param colunaInicial Coluna de onde a carta sairia.
     * @param colunaFinal Coluna para onde a carta iria.
     * @param estrutura Estrutura que contém as cartas do jogo.
     * @return true Se for possível realizar a movimentação.
     * @return false Se não for possível realizar a movimentação.
     */
    virtual bool podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) = 0;

    /**
     * @brief Recupera a mensagem de erro.
     * 
     * @return std::string Mensagem de erro.
     */
    virtual std::string getMensagemErro() const = 0;
};

#endif