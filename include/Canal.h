#ifndef CANAL_H
#define CANAL_H

#include <string>
#include "Mensagem.h"

class Canal{
    protected:
        std::string nome;
    public:
        std::string getNome();
        virtual std::string getTipo() const = 0;
};

#endif