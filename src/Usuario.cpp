#include "Usuario.h"

Usuario::Usuario(std::string email, std::string senha, std::string nome, int id) {
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->id = id;
}

std::string Usuario::getNome() {
    return this->nome;
}

std::string Usuario::getEmail() {
    return this->email;
}

int Usuario::getID() {
    return this->id;
}

bool Usuario::confereSenha(std::string senha) {
    if (this->senha == senha) {
        return true;
    } 

    return false;
}