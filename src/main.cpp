#include <iostream>
#include "Usuario.h"
#include "Sistema.h"

int main() {
    Sistema s;

    std::string linha;
    std::string comando;
    std::string email, senha, nome;

    std::cout << "BEM-VINDO AO CONCORDO!!!\n";
    do {
        std::getline(std::cin, linha);
        std::size_t posPrimeiroEspaco = linha.find(' ');
        std::size_t posSegundoEspaco = linha.find(' ', posPrimeiroEspaco + 1);
        std::size_t posTerceiroEspaco = linha.find(' ', posSegundoEspaco + 1);

        if (posPrimeiroEspaco != std::string::npos) {
            comando = linha.substr(0, posPrimeiroEspaco);
        } else {
            comando = linha;
        }

        if(comando == "quit") {
            std::cout << "Saindo do Concordo\n";
        } else if (comando == "creat-user") {
            std::cout << "criando User...\n";
            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco != std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1, posTerceiroEspaco - posSegundoEspaco - 1);
                nome = linha.substr(posTerceiroEspaco + 1);

            s.criarUsuario(email, senha, nome);        

            } else {
                std::cout << "comando creat-user com parametros invalidos!!!\n";
            }
                       
        } else if (comando == "login") {
            if(posSegundoEspaco != std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1);

                s.login(email, senha);
                
            } else {
                std::cout << "comando login com parametros invalidos!!!\n";
            }

        } else {
           std::cout << "comando invalido!\n";
        }

    } while (comando != "quit");
    
    return 0;
}