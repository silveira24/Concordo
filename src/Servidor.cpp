#include "Servidor.h"

Servidor::Servidor(std::string nome, int IDdono){
    this->nome = nome;
    this->usuarioDonoId = IDdono;
    this->codigoConvite = "";
}

Servidor::~Servidor() {
    while(this->canais.size() != 0){
        delete this->canais[0];
        this->canais.erase(this->canais.begin()); 
    }
}

std::string Servidor::getNome(){
    return this->nome;
}

int Servidor::getIDdono(){
    return this->usuarioDonoId;
}

std::string Servidor::getDescricao() {
    return this->descricao;
}

std::string Servidor::getConvite() {
    return this->codigoConvite;
}

void Servidor::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

void Servidor::setConvite(std::string convite) {
    this->codigoConvite = convite;
}

void Servidor::adicionaParticipante(int ID) {
    if(!this->usuarioParticipa(ID)) {
        this->participantesIDs.push_back(ID);
    }
}

bool Servidor::usuarioParticipa(int ID) {
    for(int i = 0; i < this->participantesIDs.size(); i++) {
        if(ID == this->participantesIDs[i]) {
            return true;
        }
    }

    return false;
}

bool Servidor::verificaConvite(std::string convite) {
    if(this->codigoConvite == ""){
        return true;
    }
    if(this->codigoConvite == convite) {
        return true;
    } else {
        return false;
    }
}

int Servidor::tamListaParticipantes() {
    return this->participantesIDs.size();
}

int Servidor::IDparticipante(int indice) {
    return this->participantesIDs[indice];
}

bool Servidor::existeCanal(std::string nome, std::string tipo) {
    for(int i = 0; i < this->canais.size(); i++){
        if(this->canais[i]->getNome() == nome && this->canais[i]->getTipo() == tipo) {
            return true;
        }
    }
    return false;
}

int Servidor::retornaIndiceCanal(std::string nome, std::string tipo) {
    for(int i = 0; i < this->canais.size(); i++){
        if(this->canais[i]->getNome() == nome && this->canais[i]->getTipo() == tipo) {
            return i;
        }
    }
    return -1;
}

void Servidor::criarCanal(std::string nome, std::string tipo) {
    if(tipo == "texto") {
        CanalTexto* canal = new CanalTexto(nome);
        this->canais.push_back(canal);
    } else if(tipo == "voz") {
        CanalVoz* canal = new CanalVoz(nome);
        this->canais.push_back(canal);
    }  
}

void Servidor::listarCanais() {
    std::cout << "#canais de texto\n";
    for(int i = 0; i < this->canais.size(); i++) {
        if(this->canais[i]->getTipo() == "texto") {
            std::cout << this->canais[i]->getNome() << std::endl;
        }
    }

    std::cout << "#canais de audio\n";
    for(int i = 0; i < this->canais.size(); i++) {
        if(this->canais[i]->getTipo() == "voz") {
            std::cout << this->canais[i]->getNome() << std::endl;
        }
    }
}

void Servidor::enviarMensagemCanal(Mensagem m, int indiceCanal) {
    this->canais[indiceCanal]->adicionarMensagem(m);
}

Canal* Servidor::retornaCanal(int indice) {
    if(indice < this->canais.size()){
        return this->canais[indice];
    }
    return nullptr;
}

int Servidor::getTamCanais() {
    return this->canais.size();
}