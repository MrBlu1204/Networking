#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{ int ss,sb;
  ss=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(6011);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(ss,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));
    struct sockaddr_in tempsendaddr;
    char msg[]="Thank You!";
    
    struct sockaddr_in client;
    client.sin_family=AF_INET;
    client.sin_port=ntohs(6009);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    sendto(ss,msg,sizeof(msg),0,(struct sockaddr *) &client,sizeof(struct sockaddr));
    close (ss);
}
