#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
    char* ip =  "172.253.63.100";
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in servaddr;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET,ip,&servaddr.sin_addr.s_addr); 
    int result = connect(sockfd,&servaddr,sizeof(servaddr));
    

    if (result == 0)
    {
        printf("Connection Was Successful\n");
    } 

    return 0;
}