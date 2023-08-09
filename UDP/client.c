#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
int main()
{

    char buffer[100];
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int k = bind(sockfd ,(struct sockaddr*)&client, sizeof(client));

    socklen_t client_len = sizeof(client);

    while(1)
    {
        fgets(buffer, 100, stdin);
        int sent = sendto(sockfd, buffer, sizeof(buffer), 0 ,(struct sockaddr*)&client, sizeof(client));
        int recv = recvfrom(sockfd, buffer, sizeof(buffer), 0 ,(struct sockaddr*)&client, &client_len);
        printf("Message from Server : %s", buffer);
    }


    return 0;


}