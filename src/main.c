#include "server.h"

int main() {
    
    if (!init_winsock()) return 1;
    SOCKET server_socket = create_socket();
    if (server_socket == INVALID_SOCKET) return 1;
    
    if (!bind_socket(server_socket, PORT)) return 1;
    if (!listen_socket(server_socket)) return 1;
    
    while (1) {
        SOCKET client_socket = accept_connection(server_socket);
        if (client_socket == INVALID_SOCKET) continue;
        
        receive_data(client_socket);
        send_response(client_socket);
        closesocket(client_socket);
    }
    
    cleanup(server_socket);
    return 0;
}
