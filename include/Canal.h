#ifndef CANAL_H
#define CANAL_H

#include <iostream>
#include <string>
#include "Mensagem.h"

/**
 * @brief Classe base para os canais.
 */
class Canal {
    protected:
        std::string nome; /**< O nome do canal. */
    public:
        /**
         * @brief Obtém o nome do canal.
         *
         * @return O nome do canal.
         */
        std::string getNome();

        /**
         * @brief Obtém o tipo do canal.
         *
         * @return O tipo do canal.
         */
        virtual std::string getTipo() const = 0;

        /**
         * @brief Adiciona uma mensagem ao canal.
         *
         * @param m A mensagem a ser adicionada.
         */
        virtual void adicionarMensagem(Mensagem m) const = 0;

        /**
         * @brief Retorna uma mensagem do canal com base no índice.
         *
         * @param indice O índice da mensagem desejada.
         * @return A mensagem correspondente ao índice.
         */
        virtual Mensagem retornaMensagem(int indice) const = 0;

        /**
         * @brief Obtém a quantidade de mensagens que estão armazenadas no canal.
         *
         * @return a quantidade de mensagens que estão armazenadas no canal.
         */
        virtual int tam() const = 0;
};

#endif
