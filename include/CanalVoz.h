#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "canal.h"
#include <vector>

class CanalVoz: public Canal {
    private:
        Mensagem ultimaMensagem;
    public:
        CanalVoz(std::string nome);
        std::string getTipo() const override;

};

#endif