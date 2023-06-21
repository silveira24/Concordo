#include "Servidor.h"

Servidor::Servidor(std::string nome, int IDdono){
    this->nome = nome;
    this->usuarioDonoId = IDdono;
    this->codigoConvite = "";
}

std::string Servidor::getNome(){
    return this->nome;
}

int Servidor::getIDdono(){
    return this->usuarioDonoId;
}

void Servidor::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

void Servidor::setConvite(std::string convite) {
    this->codigoConvite = convite;
}