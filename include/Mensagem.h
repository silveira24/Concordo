#ifndef MENSAGEM_H
#define MENSAGEM_H


#include <string>

class Mensagem {
    private:
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;
    public:
        Mensagem(std::string dataHora,int ID,std::string conteudo);
        Mensagem();
};

#endif