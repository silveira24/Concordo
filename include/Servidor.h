#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include <iostream>
#include "CanalTexto.h"
#include "CanalVoz.h"


/**
 * @brief Classe que representa um servidor no sistema Concordo.
 *
 * Esta classe representa um servidor no sistema Concordo, contendo informações sobre o usuário dono,
 * o nome do servidor, descrição, código de convite e a lista de canais e participantes associados a ele.
 * Ela oferece métodos para manipular essas informações, como definir a descrição, adicionar participantes,
 * verificar convite e obter informações sobre o servidor.
 */
class Servidor {
    private:
        int usuarioDonoId;                           /**< ID do usuário dono do servidor */
        std::string nome;                            /**< Nome do servidor */
        std::string descricao;                       /**< Descrição do servidor */
        std::string codigoConvite;                   /**< Código de convite para o servidor */
        std::vector<Canal *> canais;                 /**< Vetor de ponteiros para os canais do servidor */
        std::vector<int> participantesIDs;           /**< Vetor de IDs dos participantes do servidor */

    public:
        /**
         * @brief Construtor da classe Servidor
         * @param nome Nome do servidor
         * @param IDdono ID do usuário dono do servidor
         */
        Servidor(std::string nome, int IDdono);

        ~Servidor();

        /**
         * @brief Obtém o nome do servidor
         * @return Nome do servidor
         */
        std::string getNome();

        /**
         * @brief Obtém o ID do usuário dono do servidor
         * @return ID do usuário dono do servidor
         */
        int getIDdono();

        /**
         * @brief Obtém a descrição do servidor
         * @return Descrição do servidor
         */
        std::string getDescricao();

        /**
         * @brief Obtém o código convite do servidor
         * @return código convite do servidor
         */
        std::string getConvite();

        /**
         * @brief Define a descrição do servidor
         * @param descricao Descrição do servidor
         */
        void setDescricao(std::string descricao);

        /**
         * @brief Define o código de convite para o servidor
         * @param convite Código de convite para o servidor
         */
        void setConvite(std::string convite);

        /**
         * @brief Adiciona um participante ao servidor
         * @param ID ID do participante a ser adicionado
         */
        void adicionaParticipante(int ID);

        /**
         * @brief Verifica se um usuário é participante do servidor
         * @param ID ID do usuário a ser verificado
         * @return true se o usuário é participante, false caso contrário
         */
        bool usuarioParticipa(int ID);

        /**
         * @brief Verifica se um código de convite é válido para o servidor
         * @param convite Código de convite a ser verificado
         * @return true se o código é válido, false caso contrário
         */
        bool verificaConvite(std::string convite);

        /**
         * @brief Obtém o tamanho da lista de participantes do servidor
         * @return Tamanho da lista de participantes
         */
        int tamListaParticipantes();

        /**
         * @brief Obtém o ID de um participante do servidor a partir de um índice
         * @param indice Índice do participante na lista de participantes
         * @return ID do participante
         */
        int IDparticipante(int indice);

        /**
         * @brief Verifica se existe um canal com o nome e tipo especificados.
         *
         * @param nome O nome do canal a ser verificado.
         * @param tipo O tipo do canal a ser verificado.
         * @return true se o canal existe, false caso contrário.
         */
        bool existeCanal(std::string nome, std::string tipo);

        /**
         * @brief Retorna o índice do canal com o nome e tipo especificados.
         *
         * @param nome O nome do canal.
         * @param tipo O tipo do canal.
         * @return O índice do canal, ou -1 se o canal não for encontrado.
         */
        int retornaIndiceCanal(std::string nome, std::string tipo);

        /**
         * @brief Cria um novo canal com o nome e tipo especificados.
         *
         * @param nome O nome do canal a ser criado.
         * @param tipo O tipo do canal a ser criado.
         */
        void criarCanal(std::string nome, std::string tipo);

        /**
         * @brief Lista todos os canais disponíveis no servidor atual.
         */
        void listarCanais();

        /**
         * @brief Envia uma mensagem para o canal no índice especificado.
         *
         * @param m A mensagem a ser enviada.
         * @param indiceCanal O índice do canal.
         */
        void enviarMensagemCanal(Mensagem m, int indiceCanal);

        /**
         * @brief Retorna o ponteiro para o canal no índice especificado.
         *
         * @param indice O índice do canal.
         * @return Um ponteiro para o canal, ou nullptr se o canal não for encontrado.
         */
        Canal* retornaCanal(int indice);

        /**
         * @brief Obtém a quantidade de canais no servidor
         * @return quantidade de canais no servidor
         */
        int getTamCanais();

        /**
         * @brief desaloca a memoria alocada dinamicamente pelos canais do servidor
         */
        void limparCanais();

};

#endif
