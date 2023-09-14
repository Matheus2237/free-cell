/**
 * @file MovimentacaoIndevidaException.cpp
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

#include "../include/MovimentacaoIndevidaException.h"

MovimentacaoIndevidaException::MovimentacaoIndevidaException(std::string mensagem):
    mensagem(mensagem)
{}

const char* MovimentacaoIndevidaException::what() const noexcept {
    return this->mensagem.c_str();
}