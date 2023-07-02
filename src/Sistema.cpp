#include "Sistema.h"

Sistema::Sistema (){
    this->contID = 0;
    this->estado = "deslogado";
    this->IDuserLogado = 0;
    this->indiceServerAtual = - 1;
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
        if(this->estado == "servidor") {
            this->sairServidor();
        } else if (this->estado == "canal") {
            this->sairCanal();
            this->sairServidor();
        }
        std::cout << "Disconectando usuario " << this->usuarios[this->IDuserLogado - 1].getEmail() << std::endl;
        this->estado = "deslogado";
        this->IDuserLogado = 0;
    } else {
        std::cout << "nao esta conectado!\n";
    }
}

void Sistema::criarServidor(std::string nome) {
    if(this->estado != "deslogado") {
        if(!this->serverExiste(nome)){
            Servidor s(nome, this->IDuserLogado);
            s.adicionaParticipante(this->IDuserLogado);
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
    if (this->estado != "deslogado") {
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
    if(this->estado != "deslogado") {
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
                std::cout << "Voce nao pode alterar o codigo de convite de um servidor que nao foi criado por voce\n";
            }
        } else {
            std::cout << "Servidor " << nomeServidor << " nao existe!\n";
        }
    } else {
        std::cout << "precisa estar logado para modificar o codigo de convite de um servidor!\n";
    }
}

void Sistema::listarServidores() {
    if(this->estado != "deslogado"){
        for(int i = 0; i < this->servidores.size(); i++) {
            std::cout << this->servidores[i].getNome() << std::endl;
        }
    } else {
        std::cout << "precisa estar logado para ver a lista de servidores!\n";
    }
}

void Sistema::removerServidor(std::string nome) {
    if(this->estado != "deslogado"){
        if(this->serverExiste(nome)) {
            int indice = this->retornaIndiceServidor(nome);
            if(this->servidores[indice].getIDdono() == this->IDuserLogado) {
                this->servidores.erase(this->servidores.begin() + indice);
                std::cout << "servidor '" << nome << "' removido!\n";
            } else {
                std::cout << "voce nao eh dono do servidor '" << nome << "'!\n";
            }
        } else {
            std::cout << "servidor '" << nome << "' nao encontrado!\n";
        }
    } else {
        std::cout << "precisa estar logado para remover um servidor!\n";
    }
}

void Sistema::entrarServidor(std::string nome, std::string convite) {
    if(this->estado == "logado"){
        if(this->serverExiste(nome)){
            int indice = this->retornaIndiceServidor(nome);
            if(this->IDuserLogado == this->servidores[indice].getIDdono() || this->servidores[indice].verificaConvite(convite)) {
                this->estado = "servidor";
                this->indiceServerAtual = indice;
                this->servidores[indice].adicionaParticipante(this->IDuserLogado);
                std::cout << "entrou no servidor com sucesso!\n";
            } else {
                if(convite == ""){
                    std::cout << "Servidor requer codigo convite!\n";
                } else {
                    std::cout << "codigo convite incorreto!\n";
                }
            }
        } else {
            std::cout << "servidor '" << nome << "' nao encontrado!\n";
        }
    } else if(this->estado == "deslogado") {
        std::cout << "precisa estar logado para entrar em um servidor!\n";
    } else {
        std::cout << "voce ja esta em um servidor!\n";
    }
}

void Sistema::sairServidor() {
    if(this->estado == "servidor") {
        std::cout << "saindo do servidor '" << this->servidores[this->indiceServerAtual].getNome() << "'!\n";
        this->indiceServerAtual = -1;
        this->estado = "logado"; 
    } else {
        std::cout << "voce nao esta visualizando nenhum servidor!\n";
    }
}

void Sistema::listarParticipantes() {
    if(this->estado == "servidor") {
        for(int i = 0; i < this->servidores[this->indiceServerAtual].tamListaParticipantes(); i++) {
            std::cout << this->usuarios[this->servidores[this->indiceServerAtual].IDparticipante(i) - 1].getNome() << std::endl;
        }
    } else {
        std::cout << "voce nao esta visualizando nenhum servidor!\n";
    }
}

void Sistema::criarCanalServidorAtual(std::string nome, std::string tipo){
    if(this->estado == "servidor") {
        if(tipo == "voz" || tipo == "texto") {
            if(!this->servidores[this->indiceServerAtual].existeCanal(nome, tipo)){
                this->servidores[this->indiceServerAtual].criarCanal(nome, tipo);
                std::cout << "Canal de " << tipo << " '" << nome << "' criado!\n";
            } else {
                if(tipo == "texto") {
                    std::cout << "canal de texto '" << nome << "' ja existe!\n";
                } else {
                    std::cout << "canal de voz '" << nome << "' ja existe!\n";
                }
            }
        } else {   
            std::cout << "tipo de canal inválido!\n";
        }
    } else {
        std::cout << "voce precisa estar visualizando um servidor para criar um canal nele!\n";
    }
}

void Sistema::listarCanaisServidorAtual() {
    if(this->estado == "servidor") {
        this->servidores[this->indiceServerAtual].listarCanais();
    } else {
        std::cout << "voce precisa estar visualizando um servidor para listar seus canais!\n";
    }
}

void Sistema::entrarCanal(std::string nome, std::string tipo) {
    if(this->estado == "servidor") {
        if(tipo == "voz" || tipo == "texto") {
            if(this->servidores[this->indiceServerAtual].existeCanal(nome, tipo)) {
                this->estado = "canal";
                this->indiceCanalAtual = this->servidores[this->indiceServerAtual].retornaIndiceCanal(nome, tipo);
                std::cout << "Entrou no canal de " << tipo << " '" << nome << "'!\n";
            } else {
                std::cout << "canal de " << tipo << " '" << nome << "' nao existe!\n";
            }
        } else {
            std::cout << "tipo de canal inválido!\n";
        }
    } else if (this->estado == "canal") {
        std::cout << "voce ja esta visualiazando um canal!\n";
    } else {
        std::cout << "voce precisa estar visualizando um servidor para entrar em um de seus canais!\n";
    }
}

void Sistema::sairCanal() {
    if(this->estado == "canal") {
        std::cout << "saindo do canal...\n";
        this->estado = "servidor";
        this->indiceCanalAtual = -1;
    } else {
        std::cout << "voce precisa estar visualizando um canal para sair dele!\n";
    }
}

void Sistema::enviarMensagem(std::string conteudo) {
    
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* localTime = std::localtime(&currentTimeT);
    
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;

    std::stringstream ss;
    ss << "<" << std::setw(2) << std::setfill('0') << day << "/"
       << std::setw(2) << std::setfill('0') << month << "/"
       << year << " - " << std::setw(2) << std::setfill('0') << hour << ":"
       << std::setw(2) << std::setfill('0') << minute << ">";

    std::string dataHora = ss.str();



    if(this->estado == "canal") {
        Mensagem m(dataHora, this->IDuserLogado, conteudo);

        this->servidores[this->indiceServerAtual].enviarMensagemCanal(m, this->indiceCanalAtual);
    } else {
        std::cout << "voce precisa estar visualizando um canal para enviar uma mensagem!\n";
    }
}

void Sistema::listarMensagens() {
    if(this->estado == "canal"){
        if(this->servidores[this->indiceServerAtual].retornaCanal(this->indiceCanalAtual)->getTipo() == "texto") {
            if(servidores[this->indiceServerAtual].retornaCanal(this->indiceCanalAtual)->tam() == 0) {
               std::cout << "sem mensagens para exibir!\n"; 
            }
            for(int i = 0; i < servidores[this->indiceServerAtual].retornaCanal(this->indiceCanalAtual)->tam(); i++) {
                this->exibirMensagem(this->servidores[this->indiceServerAtual].retornaCanal(this->indiceCanalAtual)->retornaMensagem(i));
            }
        } else {
            std::cout << "voce precisa estar visualizando um canal de texto para listar as mensagens!\n";
        }
    } else {
        std::cout << "voce precisa estar visualizando um canal de texto para listar as mensagens!\n";
    }
}

void Sistema::exibirMensagem(Mensagem m) {
    std::cout << this->usuarios[m.getEnviadaPor() - 1].getNome() << m.getDataHora() << ":" << m.getConteudo() << std::endl;
}