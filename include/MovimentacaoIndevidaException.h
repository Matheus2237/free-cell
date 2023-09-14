/**
 * @file MovimentacaoIndevidaException.h
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

#ifndef MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#define MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#include <stdexcept>
#include <string>

/**
 * @brief Excessão para quando uma movimentação for indevida.
 * 
 * Aplicavel para impedir movimentações entre posições ilógicas ou quando
 *  há incompatibilidade entre as cartas que fazem parte dessa ação.
 */
class MovimentacaoIndevidaException : public std::exception {
private:

    /**
     * @brief Mensagem do motivo da exceção estar sendo lançada.
     * 
     */
    std::string mensagem;

public:

    /**
     * @brief Constrói um novo objeto Movimentação Indevida Exception.
     * 
     * @param mensagem Mensagem que carrega o motivo da exceção estar sendo lançada.
     */
    MovimentacaoIndevidaException(std::string mensagem);
    
    /**
     * @brief Retorna a mensagem da exceção.
     * 
     * @return const char* Mensagem da exceção.
     */
    const char* what() const noexcept override;
};

#endif