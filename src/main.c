#include <stdio.h>
#include <winsock2.h>

int main() {
    WSADATA wsa;
    SOCKET server_socket;

    // init winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    //create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    printf("Socket created successfully\n");

    printf("Winsock initialized successfully\n");

    WSACleanup();

    return 0;
}