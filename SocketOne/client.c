#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8181
int sock = 0;


//================================================================
// threading send to server 
void *SendMessage() {
    while (1) {
        char Message[2000];
        printf("%s","> ");
        gets(Message);
        fflush(stdin);
        if (send(sock, Message, strlen(Message), 0) < 0) {
            puts("Send failed");
            close(sock);    
        }
    }
}



//================================================================
// threading recived from server
void *ReceiveMessage() {
    while (1) {
        char ServerReply[2000];
        if (recv(sock, ServerReply, sizeof(ServerReply), 0) < 0) {
            puts("Recived failed");
        close(sock);    
        }
        puts(ServerReply);
    }
}



//===========================================================
int main()
{

    struct sockaddr_in serv_addr;
    pthread_t send_thread, receive_thread;
    char IpAddress[225]="192.168.81.11";
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        close(sock);
        return -1;
    }
    if(inet_pton(AF_INET, IpAddress, &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        close(sock);
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\nConnection Failed \n");
       close(sock);
       return -1;
    }
    pthread_create(&send_thread, NULL, SendMessage, NULL);
    pthread_create(&receive_thread, NULL, ReceiveMessage, NULL);
    pthread_join(receive_thread, NULL);
    pthread_join(send_thread, NULL);
    close(sock);
    return 0;
}
