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