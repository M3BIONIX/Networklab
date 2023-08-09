#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>

int main()
{
    char buffer[100];
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    socklen_t server_len = sizeof(server);

    while(1)
    {
        int recv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&server, &server_len);
        printf("Message from Client : %s \n", buffer);
        printf("Enter the Message to clinet :");
        fgets(buffer, 100, stdin);
        int send = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&server, sizeof(server));
    }

    return 0;

}