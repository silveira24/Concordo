#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include <iostream>
#include "Usuario.h"
#include "Servidor.h"

/**
 * @brief Classe que representa o sistema Concordo.
 *
 * Esta classe gerencia os usuários, servidores e interações do sistema Concordo.
 * Ela permite criar usuários, criar servidores, gerenciar participantes, realizar login e muito mais.
 */
class Sistema {
private:
    std::vector<Usuario> usuarios; /**< Vetor de usuários registrados no sistema. */
    std::vector<Servidor> servidores; /**< Vetor de servidores criados no sistema. */
    int IDuserLogado; /**< ID do usuário logado atualmente. */
    int indiceServerAtual; /**< Índice do servidor atualmente selecionado. */
    std::string nomeCanalAtual; /**< Nome do canal atualmente selecionado. */
    int contID; /**< Contador de IDs de usuários. */
    std::string estado; /**< Estado do sistema (deslogado, logado, em um servidor, ou em um canal). */

public:
    /**
     * @brief Construtor da classe Sistema.
     */
    Sistema();

    /**
     * @brief Cria um novo usuário no sistema.
     * @param email O email do usuário.
     * @param senha A senha do usuário.
     * @param nome O nome do usuário.
     */
    void criarUsuario(std::string email, std::string senha, std::string nome);

    /**
     * @brief Verifica se um email já está sendo usado por outro usuário.
     * @param email O email a ser verificado.
     * @return true se o email já está em uso, false caso contrário.
     */
    bool emailUsado(std::string email);

    /**
     * @brief Verifica se um servidor já existe no sistema.
     * @param nome O nome do servidor a ser verificado.
     * @return true se o servidor já existe, false caso contrário.
     */
    bool serverExiste(std::string nome);

    /**
     * @brief Retorna o índice de um servidor no vetor de servidores.
     * @param nome O nome do servidor.
     * @return O índice do servidor no vetor de servidores. Retorna -1 se o servidor não for encontrado.
     */
    int retornaIndiceServidor(std::string nome);

    /**
     * @brief Realiza o login de um usuário no sistema.
     * @param email O email do usuário.
     * @param senha A senha do usuário.
     */
    void login(std::string email, std::string senha);

    /**
     * @brief Desconecta o usuário do sistema.
     */
    void disconectar();

    /**
     * @brief Cria um novo servidor no sistema.
     * @param nome O nome do servidor.
     */
    void criarServidor(std::string nome);

    /**
     * @brief Altera a descrição de um servidor.
     * @param nomeServidor O nome do servidor.
     * @param descricao A nova descrição do servidor.
     */
    void mudarDescricaoServidor(std::string nomeServidor, std::string descricao);

    /**
     * @brief Define o código de convite para um servidor.
     * @param nomeServidor O nome do servidor.
     * @param convite O código de convite.
     */
    void setConvite(std::string nomeServidor, std::string convite);

    /**
     * @brief Lista todos os servidores do sistema.
     */
    void listarServidores();

    /**
     * @brief Remove um servidor do sistema.
     * @param nome O nome do servidor a ser removido.
     */
    void removerServidor(std::string nome);

         /**
     * @brief Entra em um servidor.
     * @param nome O nome do servidor a ser entrado.
     * @param convite O código de convite para entrar no servidor.
     */
    void entrarServidor(std::string nome, std::string convite);

    /**
     * @brief Sai do servidor atual.
     */
    void sairServidor();

    /**
     * @brief Lista os participantes do servidor atual.
     */
    void listarParticipantes();
};

#endif
