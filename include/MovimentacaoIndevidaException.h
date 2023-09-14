#ifndef MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#define MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#include <stdexcept>
#include <string>

// TODO: Documentar
class MovimentacaoIndevidaException : public std::exception {
private:
    std::string mensagem;

public:

    MovimentacaoIndevidaException(std::string mensagem);
    
    const char* what() const noexcept override;
};

#endif