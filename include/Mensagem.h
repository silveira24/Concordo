#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

/**
 * @brief Classe que representa uma mensagem.
 */
class Mensagem {
    private:
        std::string dataHora; /**< Data e hora da mensagem. */
        int enviadaPor; /**< ID da pessoa que enviou a mensagem. */
        std::string conteudo; /**< Conteúdo da mensagem. */
    public:
        /**
         * @brief Construtor da classe Mensagem.
         *
         * @param dataHora A data e hora da mensagem.
         * @param ID O ID da pessoa que enviou a mensagem.
         * @param conteudo O conteúdo da mensagem.
         */
        Mensagem(std::string dataHora, int ID, std::string conteudo);

        /**
         * @brief Construtor padrão da classe Mensagem.
         */
        Mensagem();

        /**
         * @brief Obtém a data e hora da mensagem.
         *
         * @return A data e hora da mensagem.
         */
        std::string getDataHora();

        /**
         * @brief Obtém o ID da pessoa que enviou a mensagem.
         *
         * @return O ID da pessoa que enviou a mensagem.
         */
        int getEnviadaPor();

        /**
         * @brief Obtém o conteúdo da mensagem.
         *
         * @return O conteúdo da mensagem.
         */
        std::string getConteudo();
};

#endif
