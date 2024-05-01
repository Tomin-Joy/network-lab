#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int main()
{
    int sockfd, connfd, len,n=0;
    char buff[MAX];
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);
    bzero(buff, MAX);
    read(connfd, buff, sizeof(buff));
    printf("From client: %s\t To client : ", buff);
    bzero(buff, MAX);
    while ((buff[n++] = getchar()) != '\n');
    write(connfd, buff, sizeof(buff));
    close(sockfd);
}
