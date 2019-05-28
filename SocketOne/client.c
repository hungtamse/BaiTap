#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 8181

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *StrInput;
    char add[225]="192.168.81.11";
    int Continue = 1;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        close(sock);
        return -1;
    }
    if(inet_pton(AF_INET, add, &serv_addr.sin_addr) <= 0)
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
    while(Continue == 1){
        char StrTemp[225];
        printf("Please input messenger to sent server\n");
        gets(StrTemp);
        fflush(stdin);
        StrInput = &StrTemp;
        send(sock , StrInput , strlen(StrInput) , 0 );
        if (strcmp(StrTemp, "bye") == 0)
        {
            Continue = 0;
        }
        fflush(stdin);

    }
    close(sock);
    return 0;
}
