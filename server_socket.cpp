#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <thread>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main(){

    //1. Windows 소켓 구조체 생성
    WSADATA wsaData; 
    if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0){
        cout << "WSADATA 생성에 실패했습니다" << endl;
        return 1;
    }
}