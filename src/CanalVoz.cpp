#include "CanalVoz.h"

CanalVoz::CanalVoz(std::string nome){
    this->nome = nome;
}

std::string CanalVoz::getTipo() const {
    return "voz";
}