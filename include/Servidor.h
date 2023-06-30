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

        bool existeCanal(std::string nome, std::string tipo);

        int retornaIndiceCanal(std::string nome, std::string tipo);

        void criarCanal(std::string nome, std::string tipo);

        void listarCanais();

};

#endif
