#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
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
    int indiceCanalAtual; /**< Nome do canal atualmente selecionado. */
    int contID; /**< Contador de IDs de usuários. */
    std::string estado; /**< Estado do sistema (deslogado, logado, em um servidor, ou em um canal). */
    /**
    * @brief Salva os usuários registrados no sistema no arquivo usuarios.txt.
    */
    void salvarUsuarios();
    /**
    * @brief Salva os servidores criados no sistema no arquivo servidores.txt.
    */
    void salvarServidores();
    /**
    * @brief Carrega os usuários registrados previamente no arquivo usuarios.txt.
    */
    void carregarUsuarios();
    /**
    * @brief Carrega os servidores registrados previamente no arquivo servidores.txt.
    */
    void carregarServidores();
    /**
    * @brief Limpa o sistema, removendo todos os usuários e servidores.
    */
    void limparSistema();

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

    /**
     * @brief Cria um canal novo no servidor atual.
     * @param nome O nome do canal a ser criado.
     * @param tipo O tipo do cana a ser criado (de voz ou de texto).
     */

    /**
     * @brief Cria um novo canal no servidor atual com o nome e tipo especificados.
     *
     * @param nome O nome do canal a ser criado.
     * @param tipo O tipo do canal a ser criado.
     */
    void criarCanalServidorAtual(std::string nome, std::string tipo);

    /**
     * @brief Lista todos os canais do servidor atual.
     */
    void listarCanaisServidorAtual();

    /**
     * @brief Entra no canal com o nome e tipo especificados do servidor atual.
     *
     * @param nome O nome do canal a ser acessado.
     * @param tipo O tipo do canal a ser acessado.
     */
    void entrarCanal(std::string nome, std::string tipo);

    /**
     * @brief Sai do canal atual.
     */
    void sairCanal();

    /**
     * @brief Envia uma mensagem para o canal atual.
     *
     * @param conteudo O conteúdo da mensagem a ser enviada.
     */
    void enviarMensagem(std::string conteudo);

    /**
     * @brief Lista as mensagens do canal atual.
     */
    void listarMensagens();

    /**
     * @brief Exibe uma mensagem específica.
     *
     * @param m A mensagem a ser exibida.
     */
    void exibirMensagem(Mensagem m);

    /**
     * @brief Salva o estado atual do sistema em arquivos.
     *
     * Esta função salva os usuários e servidores do sistema em arquivos separados.
     * Os usuários são salvos no arquivo "usuarios.txt" e os servidores no arquivo "servidores.txt".
     */
    void salvar();

    /**
     * @brief Carrega o estado anteriormente salvo do sistema a partir de arquivos.
     *
     * Esta função carrega os usuários e servidores previamente salvos nos arquivos "usuarios.txt" e "servidores.txt",
     * respectivamente, e os carrega para o sistema.
     */
    void carregar();

    /**
     * @brief Limpa os canais de todos os servidores.
     *
     * Esta função percorre todos os servidores do sistema e remove todos os canais presentes em cada um deles.
     * Os canais são removidos, liberando a memória alocada para eles.
     */
    void limparCanaisServidores();

};

#endif
