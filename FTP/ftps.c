#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>

#define PORT 3003

int main(){

    char buffer[100];
    int read, client_socket;
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if( k < 0)
        printf("error in binding");
    
    listen(sockfd,3);

    while(1)
    {
        
        printf("Connected to client %s:%d \n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
        FILE *file = fopen("server.txt","w");
        if(!file)
            printf("Error");
        socklen_t client_len = sizeof(client);
        client_socket = accept(sockfd, (struct sockaddr*)&client, &client_len);
        while((read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0)
          {  fwrite(buffer, sizeof(buffer), read, file); }
         printf("%s \n", buffer);
        fclose(file);
    }

    return 0;
}