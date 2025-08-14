#include "utils.hpp"
#include <stdlib.h>
#include <cstring>

int parsePort(int argc, char *argv[]){
  int port = 0;
  for (int i = 1; i < argc; i++) {
    if ((strcmp(argv[i], "-p" ) == 0 || strcmp(argv[i], "--port") == 0) && i + 1 < argc) {
      port = atoi(argv[i + 1]);
      break;
    }
  }
  return port;
}