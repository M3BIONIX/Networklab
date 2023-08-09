#include<stdio.h>
#include<time.h>
#include<netdb.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>

int main( int argc, char *argv[])
{
    int num;
    if( argc != 2)
        printf("Input format incorrect");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if( k < 0)
        printf(" Error in binding");

   
    socklen_t server_len = sizeof(server);

    while(1)
    {
        recvfrom(sockfd, &num, sizeof(num), 0, (struct sockaddr*)&server,&server_len);
         time_t current_time = time(NULL);
        printf("The time requested by client %s",ctime(&current_time));
        sendto(sockfd, &current_time, sizeof(current_time),0, (struct sockaddr*)&server, sizeof(server));
        exit(0);
    }

return 0;
}