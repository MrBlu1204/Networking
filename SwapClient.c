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
    server_address.sin_port = htons(6001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int stat = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    stat == -1 ? printf("Error During Connect\n") : printf("Connection Established\n");
    int size;
    printf("Enter Size of the Array:");
    scanf("%d",&size);
    int msg[size];
    printf("Enter Elements:");
    for(int i=0; i<size; i++){
       scanf("%d",&msg[i]);
    }
    send(client_socket, msg, sizeof(int)*size, 0);
    
    int buf[size];
    recv(client_socket, &buf, sizeof(buf),0);
    printf("Recieved from Server: New array is:");
    for(int i=0;i<size;i++)
       printf(" %d",buf[i]);
    printf("\n");
    close(client_socket);
    return 0;
}
