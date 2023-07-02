#include "CanalTexto.h"

CanalTexto::CanalTexto(std::string nome){
    this->nome = nome;
}

std::string CanalTexto::getTipo() const {
    return "texto";
}

void CanalTexto::adicionarMensagem(Mensagem m) const{
    this->mensagens.push_back(m);
}

Mensagem CanalTexto::retornaMensagem(int indice) const {
    return this->mensagens[indice];
}

int CanalTexto::tam()const {
    return this->mensagens.size();
}