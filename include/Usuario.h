#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;

    public:
        Usuario(std::string email, std::string senha, std::string nome, int id);
        std::string getNome();
        std::string getEmail();
        int getID();
        bool confereSenha(std::string senha);

};

#endif