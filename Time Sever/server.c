#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    socklen_t server_len = sizeof(server);
    while(1)
    {
        recvfrom(sockfd, &num, sizeof(num), 0, (struct sockaddr*)&server, &server_len);
        time_t current_time = time(NULL);
        sendto(sockfd, &current_time, sizeof(current_time), 0, (struct sockaddr*)&server, sizeof(server));
        exit(0);
    }

return 0;

}