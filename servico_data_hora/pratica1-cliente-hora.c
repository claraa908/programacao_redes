#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    struct sockaddr_in info;
    int socket_entrada;
    int tamanho_estrutura_socket;
    char endereco[9];
    char buffer[24];

    socket_entrada = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_entrada < 0) {  
        printf("Eita!\n");  exit(1); 
    }

    info.sin_family = AF_INET;
    info.sin_port = htons(7658);

    printf("Digite o endereco IP do servidor que deseja se conectar: \n");
    scanf("%s", endereco);
    inet_aton(endereco, &info.sin_addr);

    if(connect(socket_entrada, (struct sockaddr*)& info, sizeof(info)) < 0){
        printf("Eita!\n"); exit(1);
    }
    

    read(socket_entrada, buffer, 24);
    printf("Mensagem do servidor: %s\n", buffer);

    close(socket_entrada);
}
