#include<stdio.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

int main(){

char buf[100];

struct sockaddr_in client;

int sockfd = socket(AF_INET, SOCK_STREAM, 0);

client.sin_family = AF_INET;
client.sin_addr.s_addr = INADDR_ANY;
client.sin_port = 3003;

int k = connect(sockfd, (struct sockaddr*)&client, sizeof(client));

while(1)
{
    bzero(buf, sizeof(buf));
    fgets(buf, 100, stdin);
    write(sockfd, buf, sizeof(buf));
    read(sockfd, buf, sizeof(buf));
    printf("Message from Sever : %s",buf);

}

return 0;
}
