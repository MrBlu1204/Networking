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
    char buf[100];
    int len=sizeof(struct sockaddr);
    recvfrom(ss,buf,100,0,(struct sockaddr *)&tempsendaddr,&len);
    printf("Received from Client: %s \n",buf);
    
    int i=0;
    while(buf[i+1] != '\0'){
       i++;
    }
    
    char rev[100];
    for(int j=0;i >= 0;i--){
       rev[j]=buf[i];
       j++;
    }
    
    printf("Sending Message . . . . . \n");
    struct sockaddr_in client;
    client.sin_family=AF_INET;
    client.sin_port=ntohs(6009);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    sendto(ss,rev,sizeof(rev),0,(struct sockaddr *) &client,sizeof(struct sockaddr));
    printf("Message Sent.\n");
    close (ss);
}
