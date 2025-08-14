#include "server.hpp"
#include "logger.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {

    Logger logger("../logs/session.log");
    int port = parsePort(argc, argv);
    if (port == 0) {
        std::cerr << "Usage: " << argv[0] << " --port  ou -p \n";
        return 1;
    }
    Server server(port, logger);
    server.run();
    return 0;
}