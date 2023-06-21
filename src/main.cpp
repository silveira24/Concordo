#include <iostream>
#include "Usuario.h"
#include "Sistema.h"

int main() {
    Sistema s;

    std::string linha;
    std::string comando;
    std::string email, senha, nome, descricao, convite;

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
        } else if (comando == "create-user") {
            
            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco != std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1, posTerceiroEspaco - posSegundoEspaco - 1);
                nome = linha.substr(posTerceiroEspaco + 1);

            s.criarUsuario(email, senha, nome);        

            } else {
                std::cout << "comando create-user com parametros invalidos!!!\n";
            }
                       
        } else if (comando == "login") {
            if(posSegundoEspaco != std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1);

                s.login(email, senha);
                
            } else {
                std::cout << "comando login com parametros invalidos!!!\n";
            }

        } else if (comando == "disconnect") {
           s.disconectar();
        } else if (comando == "create-server"){
            if(posPrimeiroEspaco != std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1);

                s.criarServidor(nome);
            } else {
                std::cout << "comando create-server com parametros invalidos!!!\n";
            }
        } else if(comando == "set-server-desc") {
            if(posSegundoEspaco != std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                descricao = linha.substr(posSegundoEspaco + 1);
                s.mudarDescricaoServidor(nome, descricao);
            } else {
                std::cout << "comando set-server-desc com parametros invalidos!!!\n";
            }
        } else if(comando == "set-server-invite-code") {
            if(posPrimeiroEspaco != std::string::npos) {
                if(posSegundoEspaco != std::string::npos) {
                    nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                    convite = linha.substr(posSegundoEspaco + 1);
                } else {
                    nome = linha.substr(posPrimeiroEspaco + 1);
                    convite = "";
                }

                s.setConvite(nome, convite);
            } else {
                std::cout << "comando set-server-invite-code com parametros invalidos!!!\n";
            }
        } else if(comando == "list-servers") {
            s.listarServidores();
        } else if (comando == "remove-server"){
            if(posPrimeiroEspaco != std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1);
                s.removerServidor(nome);
            } else {
                std::cout << "comando remove-server com parametros invalidos!!!\n";
            }
        } else if (comando == "enter-server"){
            if(posPrimeiroEspaco != std::string::npos) {
                if(posSegundoEspaco != std::string::npos){
                    nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                    convite = linha.substr(posSegundoEspaco + 1);
                } else {
                    nome = linha.substr(posPrimeiroEspaco + 1);
                    convite = "";
                }

                s.entrarServidor(nome, convite);
            } else {
                std::cout << "comando enter-server com parametros invalidos!!!\n";
            }
        } else if(comando == "leave-server") {
            s.sairServidor();
        } else if(comando == "list-participants") {
            s.listarParticipantes();
        } else {
            std::cout << "comando invalido!\n";
        }

    } while (comando != "quit");
    
    return 0;
}