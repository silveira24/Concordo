#include "Sistema.h"

/**
 * @brief Função principal do programa.
 * 
 * @return 0 se o programa for concluído com sucesso.
 */
int main() {
    Sistema s;

    std::string linha;
    std::string comando;
    std::string email, senha, nome, descricao, convite, tipo, conteudo;

    std::cout << "BEM-VINDO AO CONCORDO!!!\n";
    s.carregar();
    
    // Loop principal do programa
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

        // Verifica o comando digitado pelo usuário
        if(comando == "quit") {
            if(posPrimeiroEspaco == std::string::npos){
                std::cout << "Saindo do Concordo\n";
            } else {
                std::cout << "comando quit com parametros invalidos!!!\n";
                comando = "";
            }
        } else if (comando == "create-user") {
            s.carregar();

            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco != std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1, posTerceiroEspaco - posSegundoEspaco - 1);
                nome = linha.substr(posTerceiroEspaco + 1);

                // Cria um novo usuário
                s.criarUsuario(email, senha, nome);
                s.salvar();    

            } else {
                std::cout << "comando create-user com parametros invalidos!!!\n";
            }
                       
        } else if (comando == "login") {
            s.carregar();
            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco == std::string::npos) {
                email = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                senha = linha.substr(posSegundoEspaco + 1);

                // Realiza o login do usuário
                s.login(email, senha);
                
            } else {
                std::cout << "comando login com parametros invalidos!!!\n";
            }

        } else if (comando == "disconnect") {
            s.carregar();
           // Desconecta do Concordo
            if(posPrimeiroEspaco == std::string::npos) {
                s.disconectar();
            } else {
                std::cout << "comando disconnect com parametros invalidos!!!\n";
            }
        } else if (comando == "create-server"){
            s.carregar();

            if(posPrimeiroEspaco != std::string::npos && posSegundoEspaco == std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1);

                // Cria um novo servidor
                s.criarServidor(nome);
                s.salvar();
            } else {
                std::cout << "comando create-server com parametros invalidos!!!\n";
            }
        } else if(comando == "set-server-desc") {
            s.carregar();

            std::size_t posPrimeiraAspa = linha.find('\"');
            std::size_t posSegundaAspa = linha.find('\"', posPrimeiraAspa + 1);
            std::string resto = linha.substr(posSegundaAspa + 1);
            if(posSegundoEspaco != std::string::npos && posPrimeiraAspa != std::string::npos && posSegundaAspa != std::string::npos && resto == "") {
                nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                descricao = linha.substr(posPrimeiraAspa + 1, posSegundaAspa - posPrimeiraAspa - 1);

                // Define a descrição do servidor
                s.mudarDescricaoServidor(nome, descricao);
                s.salvar();
            } else {
                std::cout << "comando set-server-desc com parametros invalidos!!!\n";
            }
        } else if(comando == "set-server-invite-code") {
            s.carregar();

            if(posPrimeiroEspaco != std::string::npos && (posTerceiroEspaco == std::string::npos || posSegundoEspaco == std::string::npos)) {
                if(posSegundoEspaco != std::string::npos) {
                    nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                    convite = linha.substr(posSegundoEspaco + 1);
                } else {
                    nome = linha.substr(posPrimeiroEspaco + 1);
                    convite = "";
                }

                // Define o código de convite do servidor
                s.setConvite(nome, convite);
                s.salvar();
            } else {
                std::cout << "comando set-server-invite-code com parametros invalidos!!!\n";
            }
        } else if(comando == "list-servers") {
            s.carregar();
            // Lista os servidores disponíveis
            if(posPrimeiroEspaco == std::string::npos){
                s.listarServidores();
            } else {
                std::cout << "comando list-servers com parametros invalidos!!!\n";
            }
        } else if (comando == "remove-server"){
            s.carregar();

            if(posPrimeiroEspaco != std::string::npos && posSegundoEspaco == std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1);

                // Remove um servidor
                s.removerServidor(nome);
                s.salvar();
            } else {
                std::cout << "comando remove-server com parametros invalidos!!!\n";
            }
        } else if (comando == "enter-server"){
            s.carregar();

            if(posPrimeiroEspaco != std::string::npos && (posTerceiroEspaco == std::string::npos || posSegundoEspaco == std::string::npos)) {
                if(posSegundoEspaco != std::string::npos){
                    nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                    convite = linha.substr(posSegundoEspaco + 1);
                } else {
                    nome = linha.substr(posPrimeiroEspaco + 1);
                    convite = "";
                }

                // Entra em um servidor
                s.entrarServidor(nome, convite);
                s.salvar();
            } else {
                std::cout << "comando enter-server com parametros invalidos!!!\n";
            }
        } else if(comando == "leave-server") {
            s.carregar();

            // Sai do servidor atual
            if(posPrimeiroEspaco == std::string::npos) {
                s.sairServidor();
            } else {
                std::cout << "comando leave-server com parametros invalidos!!!\n";
            }
        } else if(comando == "list-participants") {
            s.carregar();

            // Lista os participantes do servidor atual
            if(posPrimeiroEspaco == std::string::npos) {
                s.listarParticipantes();
            } else {
                std::cout << "comando list-participants com parametros invalidos!!!\n";
            }
        } else if(comando == "create-channel") {
            s.carregar();

            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco == std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                tipo = linha.substr(posSegundoEspaco + 1);

                s.criarCanalServidorAtual(nome, tipo);
                s.salvar();
            } else {
                std::cout << "comando create-channel com parametros invalidos!!!\n";
            }
        } else if(comando == "list-channels") {
            s.carregar();

            if(posPrimeiroEspaco == std::string::npos) {
                s.listarCanaisServidorAtual();
            } else {
                std::cout << "comando list-channels com parametros invalidos!!!\n";
            }
        } else if(comando == "enter-channel"){
            s.carregar();

            if(posSegundoEspaco != std::string::npos && posTerceiroEspaco == std::string::npos) {
                nome = linha.substr(posPrimeiroEspaco + 1, posSegundoEspaco - posPrimeiroEspaco - 1);
                tipo = linha.substr(posSegundoEspaco + 1);

                s.entrarCanal(nome, tipo);
            } else {
                std::cout << "comando enter-channel com parametros invalidos!!!\n";
            }
        } else if(comando == "leave-channel") {
            s.carregar();

            if(posPrimeiroEspaco == std::string::npos){
                s.sairCanal();
            } else {
                std::cout << "comando leave-channel com parametros invalidos!!!\n";
            }
        } else if(comando == "send-message") {
            s.carregar();

            if (posPrimeiroEspaco != std::string::npos){
                conteudo = linha.substr(posPrimeiroEspaco + 1);

                s.enviarMensagem(conteudo);
                s.salvar();
            } else {
                std::cout << "comando send-message com parametros invalidos!!!\n";
            }
        } else if(comando == "list-messages") {
            s.carregar();

            if(posPrimeiroEspaco == std::string::npos) {
                s.listarMensagens();
            } else {
                std::cout << "comando list-messages com parametros invalidos!!!\n";
            }
        } else {
            s.carregar();
            std::cout << "comando invalido!\n";
        }

    } while (comando != "quit");

    s.limparCanaisServidores();

    return 0;
}
