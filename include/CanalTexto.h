#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "canal.h"
#include <vector>

/**
 * @brief Classe que representa um canal de texto.
 */
class CanalTexto : public Canal {
    private:
        mutable std::vector<Mensagem> mensagens; /**< Vetor de mensagens do canal de texto. */
    public:
        /**
         * @brief Construtor da classe CanalTexto.
         *
         * @param nome O nome do canal de texto.
         */
        CanalTexto(std::string nome);

        /**
         * @brief Obtém o tipo do canal.
         *
         * @return O tipo do canal de texto.
         */
        std::string getTipo() const override;

        /**
         * @brief Adiciona uma mensagem ao canal de texto.
         *
         * @param m A mensagem a ser adicionada.
         */
        void adicionarMensagem(Mensagem m) const override;

        /**
         * @brief Retorna uma mensagem do canal de texto com base no índice.
         *
         * @param indice O índice da mensagem desejada.
         * @return A mensagem correspondente ao índice.
         */
        Mensagem retornaMensagem(int indice) const override;

        /**
         * @brief Obtém a quantidade de mensagens que estão armazenadas no canal de texto.
         *
         * @return  quantidade de mensagens que estão armazenadas no canal de texto.
         */
        int tam() const override;
};

#endif
