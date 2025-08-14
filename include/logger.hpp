#ifndef LOGGER
#define LOGGER

#include <string>
#include <fstream>
#include <iostream>

class Logger{
  public:
    Logger(const std::string& filename);
    void log(const std::string& message);
    ~Logger();

  private:
    std::ofstream logFile;
};


#endif /* LOGGER */
