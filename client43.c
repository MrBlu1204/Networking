#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
  {
    int cs,bs;
    cs=socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in x;
    x.sin_family=AF_INET;
    x.sin_port=ntohs(6009);
    x.sin_addr.s_addr=inet_addr("127.0.0.1");
   
    bs=bind(cs,(struct sockaddr *)&x,sizeof(x));
    int n;
    printf("Enter the Size of Array:");
    scanf("%d",&n);
    int msg[100];
    msg[0]=n;
    printf("Enter Elements of the Array:");
    for(int i=1;i<=n;i++){
      scanf("%d",&msg[i]);
    }
   
    printf("Sending Message . . . . . \n");
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=ntohs(6011);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    sendto(cs,msg,sizeof(msg),0,(struct sockaddr *) &server,sizeof(struct sockaddr));
    printf("Message Sent.\n");
    
    close (cs);
  }
