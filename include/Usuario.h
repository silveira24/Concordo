#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @brief Classe que representa um usuário do sistema.
 *
 * Esta classe armazena informações sobre um usuário, como nome, email, senha e ID.
 * Ela fornece métodos para acessar e manipular essas informações.
 */
class Usuario {
    private:
        int id;             /**< ID do usuário */
        std::string nome;   /**< Nome do usuário */
        std::string email;  /**< Email do usuário */
        std::string senha;  /**< Senha do usuário */

    public:
        /**
         * @brief Construtor da classe Usuario
         * @param email Email do usuário
         * @param senha Senha do usuário
         * @param nome Nome do usuário
         * @param id ID do usuário
         */
        Usuario(std::string email, std::string senha, std::string nome, int id);

        /**
         * @brief Obtém o nome do usuário
         * @return Nome do usuário
         */
        std::string getNome();

        /**
         * @brief Obtém o email do usuário
         * @return Email do usuário
         */
        std::string getEmail();

        /**
         * @brief Obtém o ID do usuário
         * @return ID do usuário
         */
        int getID();

        /**
         * @brief Verifica se a senha fornecida corresponde à senha do usuário
         * @param senha Senha a ser verificada
         * @return true se as senhas coincidirem, false caso contrário
         */
        bool confereSenha(std::string senha);

};

#endif
