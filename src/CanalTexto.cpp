#include "CanalTexto.h"

CanalTexto::CanalTexto(std::string nome){
    this->nome = nome;
}

std::string CanalTexto::getTipo() const {
    return "texto";
}