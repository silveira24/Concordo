#include "Mensagem.h"

Mensagem::Mensagem(std::string dataHora,int ID,std::string conteudo){
    this->dataHora = dataHora;
    this->enviadaPor = ID;
    this->conteudo = conteudo;
}

Mensagem::Mensagem(){
    this->dataHora = "dataHora";
    this->enviadaPor = 0;
    this->conteudo = "conteudo";
}

std::string Mensagem::getDataHora() {
    return this->dataHora;
}

int Mensagem::getEnviadaPor() {
    return this->enviadaPor;
}

std::string Mensagem::getConteudo() {
    return this->conteudo;
}