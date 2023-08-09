#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<time.h>
#include<netdb.h>
#include<stdlib.h>

int main( )
{

    int num = 1;

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;uuu
    client.sin_port = 3003;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    socklen_t client_len = sizeof(client);
    time_t current_time, rtt;
    sendto(sockfd, &num, sizeof(num), 0, (struct sockaddr*)&client, sizeof(client));
    time_t start = time(NULL);
    clock_t start_clock = clock();
    recvfrom(sockfd, &current_time, sizeof(current_time), 0, (struct sockaddr*)&client, &client_len);
    clock_t end_clock = clock();
    rtt = time(NULL) - start;
    current_time = current_time + rtt/2;
    printf("%s",ctime(&current_time));

}
