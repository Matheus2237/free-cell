#include "../include/MovimentacaoIndevidaException.h"

MovimentacaoIndevidaException::MovimentacaoIndevidaException(char* mensagem):
    mensagem(mensagem)
{}

const char* MovimentacaoIndevidaException::what() const noexcept {
    return this->mensagem;
}