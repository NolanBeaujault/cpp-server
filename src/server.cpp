#include <iostream>
#include "server.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Server::Server(int port, Logger &logger) : port(port), logger(logger) {}

void Server::run() {
  int server = socket(AF_INET, SOCK_STREAM, 0);
  if (server == -1) {
    std::cerr << "Error creating socket" << std::endl;
    return;
  }
  logger.log("Socket created");

  sockaddr_in address;
  std::memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(server, (struct sockaddr *)&address, sizeof(address)) == -1) {
    std::cerr << "Error binding socket" << std::endl;
    close(server);
    return;
  }
  logger.log("Socket bound");

  if (listen(server, 1) == -1) {
    std::cerr << "Error listening on socket" << std::endl;
    close(server);
    return;
  }

  std::cout << "Server is listening on port " << port << std::endl;

  sockaddr_in clientAddress;
  socklen_t clientAddressLength = sizeof(clientAddress);
  int clientSocket = accept(server, (struct sockaddr *)&clientAddress, &clientAddressLength);
  if (clientSocket == -1) {
    std::cerr << "Error accepting connection" << std::endl;
    close(server);
    return;
  }
  logger.log("Client connected");

  char buffer[1024] = {0};
  ssize_t bytes_received = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); // ssize_t is a signed data type (to return negative values on error)
  if (bytes_received > 0) {
      buffer[bytes_received] = '\0'; // Null-terminate the received data (that's why we had sizeof(buffer) - 1)
      std::cout << "Received message: " << buffer << std::endl;
      logger.log("Message received and displayed");
    } else {
      std::cerr << "Error receiving message" << std::endl;
    }
    close(clientSocket);
    close(server);
}
