#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int init_winsock(void);
SOCKET create_socket(void);
int bind_socket(SOCKET server_socket, int port);
int listen_socket(SOCKET server_socket);
SOCKET accept_connection(SOCKET server_socket);
int receive_data(SOCKET client_socket);
int send_response(SOCKET client_socket);
void cleanup(SOCKET server_socket);

#endif // SERVER_H
