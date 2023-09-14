#include "../include/MovimentacaoIndevidaException.h"

MovimentacaoIndevidaException::MovimentacaoIndevidaException(std::string mensagem):
    mensagem(mensagem)
{}

const char* MovimentacaoIndevidaException::what() const noexcept {
    return this->mensagem.c_str();
}