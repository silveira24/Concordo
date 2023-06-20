#include "Servidor.h"

Servidor::Servidor(std::string nome, int IDdono){
    this->nome = nome;
    this->usuarioDonoId = IDdono;
}

std::string Servidor::getNome(){
    return this->nome;
}