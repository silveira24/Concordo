#include "Sistema.h"

Sistema::Sistema () {
    this->contID = 0;
    this->estado = "deslogado";
    this->IDuserLogado = 0;
}

void Sistema::criarUsuario (std::string email, std::string senha, std::string nome) {
    if(this->estado == "deslogado") {
        if (!this->emailUsado(email)) {
            this->contID++;
            Usuario u(email, senha, nome, this->contID);
            this->usuarios.push_back(u);
            std::cout << "Usuario criado!\n";
        } else {
            std::cout << "Usuario já existe!\n";
        }
    } else {
        std::cout << "logado em uma conta! para criar novo usuario precisa estar deslogado!\n";
    }

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
    if(this->estado == "deslogado") {
        if (this->emailUsado(email)) {
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
        } else {
            std::cout << "email nao cadastrado!\n";
        }
    } else {
        std::cout << "ja esta logado em uma conta\n";
    }
}

void Sistema::disconectar() {
    if (this->estado != "deslogado") {
        std::cout << "Disconectando usuario " << this->usuarios[this->IDuserLogado - 1].getEmail() << std::endl;
        this->estado = "deslogado";
        this->IDuserLogado = NULL;
    } else {
        std::cout << "nao esta conectado!\n";
    }
}