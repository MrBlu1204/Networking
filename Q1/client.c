#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    client_socket < 0 ? printf("Error Making Socket\n") : printf("Socket Successful\n");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int stat = connect(client_socket, (struct sockaddr *) & server_address, sizeof(server_address));
    stat == -1 ? printf("Error During Connect\n") : printf("Connection Established\n");

    char msg[100] = "HELLO KIIT!";
    send(client_socket, msg, sizeof(msg), 0);

    char buf[100];
    recv(client_socket, &buf, sizeof(buf), 0);
    printf("Received from Server : %s\n", buf);

    return 0;
}
