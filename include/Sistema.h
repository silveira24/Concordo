#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include <vector>
#include <iostream>
#include "Usuario.h"
#include "Servidor.h"

class Sistema {
    public:
        std::vector<Usuario> usuarios;
        std::vector<Servidor> servidores;
        int IDuserLogado;
        std::string nomeServerAtual;
        std::string nomeCanalAtual;
        int contID;
        std::string estado;

    public:
        Sistema();
        void criarUsuario(std::string email, std::string senha, std::string nome);
        bool emailUsado(std::string email);
        bool serverExiste(std::string nome);
        void login(std::string email, std::string senha);
        void disconectar();
        void criarServidor(std::string nome);
};

#endif