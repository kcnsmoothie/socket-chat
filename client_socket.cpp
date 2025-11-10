#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "WSAStartup failed" << endl;
        return 1;
    }

    SOCKET clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSock == INVALID_SOCKET)
    {
        cout << "socket create failed" << endl;
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4882);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSock, (SOCKADDR *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        cout << "server connect failed" << endl;
        closesocket(clientSock);
        WSACleanup();
        return 1;
    }

    cout << "server connect success!" << endl;

    string msg = "Hello from client!";
    send(clientSock, msg.c_str(), msg.size(), 0);

    cout << "message sended!" << endl;

    closesocket(clientSock);
    WSACleanup();
}
