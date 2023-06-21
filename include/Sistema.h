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
        int indiceServerAtual;
        std::string nomeCanalAtual;
        int contID;
        std::string estado;

    public:
        Sistema();
        void criarUsuario(std::string email, std::string senha, std::string nome);
        bool emailUsado(std::string email);
        bool serverExiste(std::string nome);
        int retornaIndiceServidor(std::string nome);
        void login(std::string email, std::string senha);
        void disconectar();
        void criarServidor(std::string nome);
        void mudarDescricaoServidor(std::string nomeServidor, std::string descricao);
        void setConvite(std::string nomeServidor, std::string convite);
        void listarServidores();
        void removerServidor(std::string nome);
        void entrarServidor(std::string nome, std::string convite);
};

#endif