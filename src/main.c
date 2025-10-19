#include <stdio.h>
#include <winsock2.h>

int main() {
    WSADATA wsa;

    // init winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Winsock initialized successfully\n");

    WSACleanup();

    return 0;
}