#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <malloc.h>
#include <pthread.h>

struct sockaddr_in remoteAddr;
int valueOfAccept;

void *RecieveFromClient(void* ptr){
    while(1){
        char string[1024];
        memset(&string, '\0', sizeof(string));
        recv(valueOfAccept, string, sizeof(string), 0);
        puts(string);
        printf("%s ",inet_ntoa(remoteAddr.sin_addr));
        printf("\n");
        if(strcmp(string,"EXIT")==0)
            break;
        memset(&string, '\0', sizeof(string));
    }
}

void *SendToClient(void* ptr){
    while(1){
        char string[1024];
        memset(&string, '\0', sizeof(string));
        gets(string);
        send(valueOfAccept, string, sizeof(string), 0);
        if(strcmp(string,"EXIT")==0)
            break;
        memset(&string, '\0', sizeof(string));
    }
}

int main(){
    int valueOFSocket;
    int valueOfBind;
    int valueOfListen;
    int valueOfShutdown;
    struct sockaddr_in address;
    socklen_t remoteAddr_len;

    pthread_t recieveClient;
    pthread_t sendClient;

    valueOFSocket=socket(AF_INET, SOCK_STREAM, 0);
    if(valueOFSocket<0){
        printf("Error create server");
        return -1;
    }
    else
        printf("Create server successful\n");

    memset(&address, '\0', sizeof(address));
    memset(&remoteAddr, '\0', sizeof(remoteAddr));

    address.sin_port=htons(8181);
    address.sin_family=AF_INET;
    inet_aton("192.168.81.11", &address.sin_addr.s_addr);
    valueOfBind=bind(valueOFSocket,(struct sockaddr*)&address, sizeof(address));
    if(valueOfBind==0)
        printf("Bind is successful\n");
    else{
        printf("Error bind");
        goto CLOSE;
    }

    valueOfListen=listen(valueOFSocket, 10);
    if(valueOfListen==0)
        printf("Listening...");
    else{
        goto CLOSE;
    }
    remoteAddr_len=sizeof(remoteAddr);
    valueOfAccept=accept(valueOFSocket, (struct sockaddr*)&remoteAddr, &remoteAddr_len);
    if(valueOfAccept>0){
        printf("accept successful !\n");
//        printf("%d \n",remoteAddr.sin_addr);
    }
    else
        goto CLOSE;

    pthread_create(&recieveClient, NULL, RecieveFromClient, NULL);
    pthread_create(&sendClient, NULL, SendToClient, NULL);
    pthread_join(recieveClient, NULL);
    pthread_join(sendClient, NULL);

    valueOfShutdown=shutdown(valueOFSocket, SHUT_RDWR);
    if(valueOfShutdown==0)
        printf("Shutdown successful");
    else
        CLOSE:
            close(valueOFSocket);
            return -1;

    return 0;
}

