#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

void main(){
    struct sockaddr_in sa, cli;
    int n, sockfd;
    
    int len;
    char buff[100];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0){
        printf("Error in Socket\n");
        exit(0);
    }
    
    else printf("Socket is Opened\n");
    
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8007);
    
    if(connect(sockfd,(struct sockaddr*)&sa,sizeof(sa)) < 0){
        printf("Error in connection failed");
        exit(0);
    }
    else printf("\nconnected successfully");
    if(n=read(sockfd,buff,sizeof(buff))<0){
        printf("\nError in Reading");
        exit(0);
    }
    else{
        printf("\nMessage Read %s",buff);
    }
}