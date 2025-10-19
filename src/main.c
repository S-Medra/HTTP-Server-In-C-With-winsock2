#include <stdio.h>
#include <winsock2.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int bytes_received;

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

   // Config the address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //binding
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Socket successfully bound to port %d\n", PORT);

    // Listening
    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    printf("Server is listening for connections...\n");

    while (1) {
        // Accept
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_socket == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }
        printf("Connection accepted from %s:%d\n",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        //Read
        bytes_received = recv(client_socket, buffer, 
        BUFFER_SIZE - 1, 0);

        if (bytes_received == SOCKET_ERROR) {
            printf("recv failed. Error Code: %d\n", WSAGetLastError());
            closesocket(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0'; // Null terminate
        printf("Received: %s\n", buffer);


        closesocket(client_socket);
    }
    //clean up
    closesocket(server_socket);
    WSACleanup();

    return 0;
}