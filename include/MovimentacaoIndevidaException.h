#ifndef MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#define MOVIMENTACAO_INDEVIDA_EXCEPTION_H
#include <stdexcept>

class MovimentacaoIndevidaException : public std::exception {
private:
    char* mensagem;

public:

    MovimentacaoIndevidaException(char* mensagem);
    
    const char* what() const noexcept override;
};

#endif