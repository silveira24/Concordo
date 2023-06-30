#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "canal.h"
#include <vector>

class CanalTexto: public Canal {
    private:
        std::vector <Mensagem> mensagens;
    public:
        CanalTexto(std::string nome);
        std::string getTipo() const override;
};

#endif