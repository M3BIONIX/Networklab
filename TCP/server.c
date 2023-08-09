#include<stdio.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

int main(){

char buf[100];

struct sockaddr_in server, client;

server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = 3003;

client.sin_family = AF_INET;
client.sin_addr.s_addr = INADDR_ANY;
client.sin_port = 3003;

int sockfd = socket(AF_INET, SOCK_STREAM, 0);
int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
if(k == -1)
    printf("Error");
listen(sockfd, 5);

socklen_t sock_len = sizeof(client);
int temp_sock = accept(sockfd, (struct sockaddr*)&client, &sock_len);

while(1)
{
    bzero(buf, sizeof(buf));
    read(temp_sock, buf, sizeof(buf));
    printf("Message from Client : %s", buf);
    fgets(buf, 100, stdin);
    write(temp_sock, buf, sizeof(buf));
}

return 0;
}