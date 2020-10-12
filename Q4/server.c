#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_socket < 0 ? printf("Error Opening Socket\n") : printf("Socket Working\n");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, 5);
    int client_socket = accept(server_socket, NULL, NULL);

    int buf[100];
    int size=recv(client_socket, &buf, sizeof(buf), 0);
    size=size/sizeof(int);
    printf("Recived from Client :");
    int sum=0;
    for(int i=0;i<size;i++)
    {
      printf(" %d",buf[i]);
      sum  += buf[i];
    }
    printf(" %d \n",sum);
    
    send(client_socket, &sum, sizeof(int),0);
    
    close(server_socket);
    return 0;
}
