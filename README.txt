Concordo


Identificação do Estudante

Nome: Gabriel Santos da Silveira
Matrícula: 20200046384
Curso: TECNOLOGIA DA INFORMAÇÃO
Universidade: UFRN - Universidade Federal do Rio Grande do Norte


Descrição

O "Concordo" é um sistema de comunicação que permite aos usuários criar servidores com 
canais de texto e voz para se comunicarem com outros usuários. Os usuários podem criar 
servidores, criar canais dentro desses servidores, entrar em servidores de outros usuários e
enviar mensagens nos canais.

Compilação e Execução
Requisitos:

Compilador C++ (recomendado: GCC ou Clang)
CMake

Compilar o programa:

mkdir build
cd build
cmake ..
cd ..
cmake --build build

Executar o programa:

./build/Concordo


Roteiro de Exemplo:

Sair do sistema: "quit"
Criar um usuário: "create-user <email> <senha_sem_espaços> <nome com espaços>"
Entrar no sistema: "login <email> <senha>"
Desconectar do Concorda: "disconnect"
Criar um servidor: "create-server <nome>"
Mudar a descrição do servidor: "set-server-desc <nome> "<descrição>""
Setar código de convite para o servidor: "set-server-invitecode <nome> <codigo>"
Listar servidores: "list-servers"
Remover servidor: "remove-server <nome>"
Entrar em um servidor: "enter-server <nome> <codigo convite>*" //*se existir
Sair de um servidor: "leave-server"
Listar pessoas no servidor: "list-participants"
Listar canais do servidor: "list-channels"
Criar um canal no servidor: "create-channel <nome> <tipo>"
Entrar em um canal do servidor: "enter-channel <nome>"
Sair do canal: "leave-channel"
Enviar mensagem para o canal: "send-message <mensagem>"
Visualizar mensagens do canal: "list-messages"

Limitações e Dificuldades

O programa "Concordo" é uma implementação simplificada de um sistema de comunicação 
e possui algumas limitações em relação a recursos e funcionalidades mais avançadas.

não há acesso à rede de dados e todas as operações 
são realizadas localmente no computador.

Durante o desenvolvimento do programa, foram encontradas algumas dificuldades na 
implementação de determinadas funcionalidades, como a manipulação correta das estruturas 
de dados e a lógica de gerenciamento de servidores e canais