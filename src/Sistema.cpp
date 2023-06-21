#include "Sistema.h"

Sistema::Sistema (){
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

bool Sistema::serverExiste (std::string nome) {
    bool existe = false;
    for(int i = 0; i < this->servidores.size(); i++) {
        if (this->servidores[i].getNome() == nome) {
            existe = true;
        }
    }

    return existe;
}

int Sistema::retornaIndiceServidor(std::string nome) {
    if(this->serverExiste(nome)) {
        int cont = 0;
        while(this->servidores[cont].getNome() != nome) {
            cont++;
        }
        return cont;
    } else {
        return -1;
    }
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
        this->IDuserLogado = 0;
    } else {
        std::cout << "nao esta conectado!\n";
    }
}

void Sistema::criarServidor(std::string nome) {
    if(this->estado == "logado") {
        if(!this->serverExiste(nome)){
            Servidor s(nome, this->IDuserLogado);
            this->servidores.push_back(s);
            std::cout << "Servidor criado!\n";
        } else {
            std::cout << "Servidor com esse nome ja existe!\n";
        }
    } else {
        std::cout << "precisa estar logado para criar um servidor!\n";
    }
}

void Sistema::mudarDescricaoServidor(std::string nomeServidor, std::string descricao) {
    if (this->estado == "logado") {
        if(this->serverExiste(nomeServidor)){
            int indice = this->retornaIndiceServidor(nomeServidor);
            if(this->IDuserLogado == this->servidores[indice].getIDdono()){
                this->servidores[indice].setDescricao(descricao);
                std::cout << "Descricao do servidor " << nomeServidor << " modificada!\n";
            } else {
                std::cout << "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce\n";
            }

        } else {
            std::cout << "Servidor " << nomeServidor << " nao existe!\n";
        }
    } else {
        std::cout << "precisa estar logado para modificar a descricao de um servidor!\n";
    }
}

void Sistema::setConvite(std::string nomeServidor, std::string convite) {
    if(this->estado == "logado") {
        if(this->serverExiste(nomeServidor)){
            int indice = this->retornaIndiceServidor(nomeServidor);
            if(this->IDuserLogado == this->servidores[indice].getIDdono()){
                this->servidores[indice].setConvite(convite);
                if(convite != "") {
                    std::cout << "Codigo de convite do servidor " << nomeServidor << " modificado!\n";
                } else {
                    std::cout << "Codigo de convite do servidor " << nomeServidor << " removido!\n";
                }
            } else {
                std::cout << "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce\n";
            }
        } else {
            std::cout << "Servidor " << nomeServidor << " nao existe!\n";
        }
    } else {
        std::cout << "precisa estar logado para modificar o codigo de convite de um servidor!\n";
    }
}