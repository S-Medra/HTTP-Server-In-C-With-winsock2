# HTTP-Server-In-C-With-Winsock2

A simple and lightweight HTTP server written in C using **Winsock2** for Windows.

## Features

- TCP socket creation
- Binding to a port
- Listening for incoming connections
- Accepting client connections
- Receiving HTTP requests
- Sending HTTP responses

## Usage

1. Compile the project using `gcc`:

   ```bash
   gcc src/main.c src/server.c -o server.exe -lws2_32
   ```

2. Run the server:

   ```bash
   ./server.exe
   ```

3. Connect to the server using `localhost:8000` or `ncat`:

   ```bash
   ncat 127.0.0.1 8000
   ```

## Notes

- This server is **minimalist** and not intended for production use.
- Designed for learning purposes to demonstrate Winsock2 TCP server functionality.

## License

This project is released under the MIT License.
