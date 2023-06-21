#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
#include "Canal.h"

class Servidor {
    private:
        int usuarioDonoId;
        std::string nome;
        std::string descricao;
        std::string codigoConvite;
        std::vector<Canal *> canais;
        std::vector<int> participantesIDs;
    public:
        Servidor(std::string nome, int IDdono);
        std::string getNome();
        int getIDdono();
        void setDescricao(std::string descricao);
        void setConvite(std::string convite);
        void adicionaParticipante(int ID);
        bool usuarioParticipa(int ID);
        bool verificaConvite(std::string convite);
        int tamListaParticipantes();
        int IDparticipante(int indice);

};

#endif