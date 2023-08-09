#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>

#define PORT 3003

int main(){

    char buffer[100];
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int k = connect(sockfd, (struct sockaddr*)&server, sizeof(server));

    FILE *file = fopen("clienttxt.txt","r");

    while(!feof(file))
    {
        int read = fread(buffer, sizeof(char), sizeof(buffer), file);
        int l = send(sockfd, buffer, read, 0);
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}