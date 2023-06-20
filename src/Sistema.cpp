#include "Sistema.h"

Sistema::Sistema () {
    this->contID = 0;
    this->estado = "deslogado";
    this->IDuserLogado = 0;
}

void Sistema::criarUsuario (std::string email, std::string senha, std::string nome) {
    this->contID++;

    Usuario u(email, senha, nome, this->contID);

    this->usuarios.push_back(u);

}

bool Sistema::emailUsado (std::string email) {
    bool usado = false;

    for (int i = 0; i < this->usuarios.size(); i++) {
        if (this->usuarios[i].getEmail() == email) {
            usado = true;
        }
    }

    return usado;
}

void Sistema::login (std::string email, std::string senha) {
    int cont = 0;
    while(this->usuarios[cont].getEmail() != email) {
        cont++;
    }

    if(this->usuarios[cont].confereSenha(senha)) {
        this->estado = "logado";
        this->IDuserLogado = this->usuarios[cont].getID();
        std::cout << "logado como " << email << std::endl;
    } else {
        std::cout << "senha nao confere!\n";
    }

}