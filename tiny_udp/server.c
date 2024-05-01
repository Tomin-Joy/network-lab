// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void main() {
	int sockfd,len, n;
	char buffer[1024],hello[256];
	struct sockaddr_in servaddr, cliaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(8080);
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	n = recvfrom(sockfd, (char *)buffer, 1024,MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);
	printf("Enter message to client : ");
	gets(hello);
	sendto(sockfd, (const char *)hello, strlen(hello),MSG_CONFIRM, (const struct sockaddr *) &cliaddr,len);
	printf("Hello message sent.\n");
}