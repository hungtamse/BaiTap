#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main(){
    int valueOFSocket;
    int valueOfBind;
    int valueOfListen;
    int valueOfAccept;
    int valueOfShutdown;
    struct sockaddr_in address, remoteAddr;
    socklen_t remoteAddr_len;
    int q=1;

    valueOFSocket=socket(AF_INET, SOCK_STREAM, 0);
    if(valueOFSocket<0)
        printf("Error create server");
    else
        printf("Create server successful\n");

    memset(&address, '0', sizeof(address));

    address.sin_port=htons(8181);
    address.sin_family=AF_INET;
    inet_aton("192.168.81.11", &address.sin_addr.s_addr);
    valueOfBind=bind(valueOFSocket,(struct sockaddr*)&address, sizeof(address));
    if(valueOfBind==0)
        printf("Bind is successful\n");
    else
        printf("Error bind");

    valueOfListen=listen(valueOFSocket, 2);
    if(valueOfListen==0)
        printf("Listening...");
    else
        printf("false");

    valueOfAccept=accept(valueOFSocket, (struct sockaddr*)&remoteAddr, &remoteAddr_len);
    if(valueOfAccept>0){
        printf("accept successful !");
        printf("%s ", inet_ntoa(remoteAddr.sin_addr));
    }
    else
        printf("false");
    while(1){
        char buf[1024];
        recv(valueOfAccept, buf, sizeof(buf), 0);
        printf("%s\n",buf);
        printf("from ip: %s \n", inet_ntoa(remoteAddr.sin_addr));
    }

    valueOfShutdown=shutdown(valueOFSocket, SHUT_RDWR);
    if(valueOfShutdown==0)
        printf("Shutdown successful");
    else
        printf("Shutdown false");

    return 0;
}
