#ifndef SERVER
#define SERVER

#include "logger.hpp"

class Server{
  public:
    Server(int port, Logger &logger);
    void run();

  private:
    int port;
    Logger &logger;
};

#endif /* SERVER */
