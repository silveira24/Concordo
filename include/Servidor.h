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
};

#endif