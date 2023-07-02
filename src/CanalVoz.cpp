#include "CanalVoz.h"

CanalVoz::CanalVoz(std::string nome){
    this->nome = nome;
}

std::string CanalVoz::getTipo() const {
    return "voz";
}

void CanalVoz::adicionarMensagem(Mensagem m) const{
    this->ultimaMensagem = m;
}

Mensagem CanalVoz::retornaMensagem(int indice) const {
    return this->ultimaMensagem;
}

int CanalVoz::tam() const {
    return 1;
}