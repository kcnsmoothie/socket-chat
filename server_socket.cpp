#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <thread>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{

    // 1. Windows 소켓 구조체 생성
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "WSADATA 생성에 실패했습니다" << endl;
        return 1;
    }

    // 2. 리스닝 소켓 생성
    SOCKET listeningSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listeningSock = INVALID_SOCKET)
    {
        cout << "listening socket을 생성할 수 없습니다." << endl;
        return 1;
    }

    // 3. IP 주소, PORT 번호 바인딩
    sockaddr_in addrServer{};
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(4882); // port 번호
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listeningSock, (SOCKADDR *)&addrServer, sizeof(addrServer));
    listen(listeningSock, SOMAXCONN); // 4. 클라이언트 요청 리스닝

    // 5. 클라이언트 연결 수락
    sockaddr_in client = {};
    int client_size = sizeof(client);

    SOCKET client_socket;
    client_socket = accept(listeningSock, (SOCKADDR *)&client, &client_size);