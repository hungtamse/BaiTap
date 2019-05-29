#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <malloc.h>
#include <pthread.h>

struct sockaddr_in remoteAddr;
int valueOfAccept;
int valueOfShutdown;
int checkDistConnect=0;

void *recieve_from_client(void* ptr){
    while(1){
        char string[1024];
        memset(&string, '\0', sizeof(string));
        recv(valueOfAccept, string, sizeof(string), 0);
        if(valueOfAccept<0)
            checkDistConnect=1;
        puts(string);
        printf("from ip: %s \n", inet_ntoa(remoteAddr.sin_addr));
        memset(&string, '\0', sizeof(string));
        if(checkDistConnect!=0)
            break;
    }
}

void *send_to_client(void* ptr){
    while(1){
        char string[1024];
        memset(&string, '\0', sizeof(string));
        gets(string);
        send(valueOfAccept, string, sizeof(string), 0);
        if(valueOfAccept<0)
            checkDistConnect=1;
        memset(&string, '\0', sizeof(string));
        if(checkDistConnect!=0)
            break;
    }
}

int main(){
    int valueOFSocket;
    int valueOfBind;
    int valueOfListen;
    struct sockaddr_in address;
    socklen_t remoteAddr_len;

    pthread_t recieveClient;
    pthread_t sendClient;
    int valueOfRecieveClient;
    int valueOfSendClient;

    valueOFSocket=socket(AF_INET, SOCK_STREAM, 0);
    if(valueOFSocket<0){
        printf("Error create server");
        return -1;
    }
    else
        printf("Create server successful\n");

    memset(&address, '0', sizeof(address));

    address.sin_port=htons(8181);
    address.sin_family=AF_INET;
    inet_aton("192.168.81.11", &address.sin_addr.s_addr);
    valueOfBind=bind(valueOFSocket,(struct sockaddr*)&address, sizeof(address));
    if(valueOfBind==0)
        printf("Bind is successful\n");
    else{
        printf("Error bind");
        CLOSE:
            free(&address);
            return -1;
    }

    valueOfListen=listen(valueOFSocket, 1);
    if(valueOfListen==0)
        printf("Listening...");
    else{
        goto CLOSE;
    }

    valueOfAccept=accept(valueOFSocket, (struct sockaddr*)&remoteAddr, &remoteAddr_len);
    if(valueOfAccept>0){
        printf("accept successful !");
        printf("%s ", inet_ntoa(remoteAddr.sin_addr));
    }
    else
        goto CLOSE;
    
    valueOfRecieveClient=pthread_create(&recieveClient, NULL, recieve_from_client, NULL);
    valueOfSendClient=pthread_create(&sendClient, NULL, send_to_client, NULL);
    pthread_join(recieveClient, NULL);
    pthread_join(sendClient, NULL);
    
    valueOfShutdown=shutdown(valueOFSocket, SHUT_RDWR);
    if(valueOfShutdown==0)
        printf("Shutdown successful");
    else
        goto CLOSE;

    return 0;
}

