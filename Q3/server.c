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

    char buf[100];
    recv(client_socket, &buf, sizeof(buf), 0);
    printf("Client : %s\n", buf);

    int vowel = 0;
    int len = strlen(buf);
    char rev[100];

    int end = len - 1;

    for (int begin = 0; begin < len; begin++) {
      rev[begin] = buf[end];
      end--;
    }

    printf("Reverse : %s\n", rev);
    int count = 0;
    for (int i = 0 ; i < len -1; i++){
        if(buf[i] == rev[i]){
            count++;
        }
    }
    if (count == len - 1){
        printf("Entered String is PALINDROME\n");
    } else {
        printf("Entered String is NOT PALINDROME\n");
    }

    return 0;
}
