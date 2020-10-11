#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{ int ss,sb;
  ss=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(6011);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(ss,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));
    
    printf("Recieving Message . . . . . \n");
    struct sockaddr_in tempsendaddr;
    int buf[100];
    int len=sizeof(struct sockaddr);
    recvfrom(ss,buf,100,0,(struct sockaddr *)&tempsendaddr,&len);
    printf("Received from Client: ");
    int i=1;
    while(i <= buf[0]){
       printf(" %d",buf[i]);
       i++;
    }
    printf("\n");
    
    
}
