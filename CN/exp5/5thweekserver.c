#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    struct sockaddr_in sa;
    struct sockaddr_in cli;
    int sockfd, conntfd;
    int len, ch;
    char str[100];
    
    time_t tick;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd<0){
        printf("error in socket\n");
        exit(0);
    }
    else printf(" Socket Opened ");
    
    bzero(&sa, sizeof(sa));
    
    sa.sin_port = htons(8007);
    sa.sin_addr.s_addr = htonl(0);
    
    if(bind(sockfd, (struct sockaddr*)&sa, sizeof(sa))<0){
        printf("Error in binding\n");
    }
    else printf(" Error Successfully ");
    
    listen(sockfd, 50);
    for(;;){
        len=sizeof(ch);
        conntfd=accept(sockfd,(struct sockaddr*)&cli,&len);
        printf(" Accepted ");
        tick=time(NULL);
        snprintf(str,sizeof(str),"%s",ctime(&tick));
        printf("%s",str);
        write(conntfd,str,100);
    }
}