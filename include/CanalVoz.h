#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "canal.h"

/**
 * @brief Classe que representa um canal de voz.
 */
class CanalVoz : public Canal {
    private:
        mutable Mensagem ultimaMensagem; /**< Última mensagem enviada no canal de voz. */
    public:
        /**
         * @brief Construtor da classe CanalVoz.
         *
         * @param nome O nome do canal de voz.
         */
        CanalVoz(std::string nome);

        /**
         * @brief Obtém o tipo do canal.
         *
         * @return O tipo do canal de voz.
         */
        std::string getTipo() const override;

        /**
         * @brief Adiciona uma mensagem ao canal de voz.
         *
         * @param m A mensagem a ser adicionada.
         */
        void adicionarMensagem(Mensagem m) const override;

        /**
         * @brief Retorna a ultima mensagem do canal.
         *
         * @param indice O índice da mensagem desejada.
         * @return A ultima mensagem enviada no canal.
         */
        Mensagem retornaMensagem(int indice) const override;

        /**
         * @brief Obtém o tamanho do canal de voz.
         *
         * @return retorna 1.
         */
        int tam() const override;
};

#endif
