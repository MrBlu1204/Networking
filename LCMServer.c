#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

int findlcm(int arr[], int n) 
{ 
    int ans = arr[0]; 
  
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

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
    int LCM = findlcm(buf, size);
    printf(" %d \n",LCM);
    
    send(client_socket, &LCM, sizeof(int),0);
    
    close(server_socket);
    return 0;
}
