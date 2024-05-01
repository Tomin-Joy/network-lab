#include <arpa/inet.h> 
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> 
#include <sys/socket.h>
#include <unistd.h> 
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int main(){
    int sockfd, connfd,n=0;
    char buff[MAX];
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
    bzero(buff, sizeof(buff));
    printf("Enter the string : ");
    while ((buff[n++] = getchar()) != '\n');
    write(sockfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    printf("From Server : %s", buff);
    close(sockfd);
}
