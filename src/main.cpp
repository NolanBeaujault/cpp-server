#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

int main(){
    // create a socket (which is the endpoint for communication)
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // now, let's set up the address structure
    sockaddr_in address;
    std::memset(&address, 0, sizeof(address)); // useful to initialize the structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // then, we associate the socket with the address
    if (bind(server, (struct sockaddr *)&address, sizeof(address)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        close(server);
        return 1;
    }

    // and put the server socket in listening mode (1 because at the moment we only want to accept one connection)
    if (listen(server, 1) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        close(server);
        return 1;
    }

    std::cout << "Server is listening on port 8080" << std::endl;

    // we wait for a client to connect
    sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket = accept(server, (struct sockaddr *)&clientAddress, &clientAddressLength);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        close(server);
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    char buffer[1024] = {0};
    ssize_t bytes_received = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); // ssize_t is a signed data type (to return negative values on error)
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data (that's why we had sizeof(buffer) - 1)
        std::cout << "Received message: " << buffer << std::endl;
    } else {
        std::cerr << "Error receiving message" << std::endl;
    }

    close(clientSocket);
    close(server);
    return 0;
}