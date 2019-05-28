#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <malloc.h>

int main(){
    int valueOFSocket;
    int valueOfBind;
    int valueOfListen;
    int valueOfAccept;
    int valueOfShutdown;
    struct sockaddr_in address, remoteAddr;
    socklen_t remoteAddr_len;

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
    while(1){
        char buf[1024];
        memset(buf, '\0', sizeof(buf));
        recv(valueOfAccept, buf, sizeof(buf), 0);
        puts(buf);
        printf("from ip: %s \n", inet_ntoa(remoteAddr.sin_addr));
        if(strcmp("EXIT",buf)==0)
            break;
    }

    valueOfShutdown=shutdown(valueOFSocket, SHUT_RDWR);
    if(valueOfShutdown==0)
        printf("Shutdown successful");
    else
        goto CLOSE;

    return 0;
}
