#include "logger.hpp"

Logger::Logger(const std::string& filename) {
  logFile.open(filename, std::ios::app);
  if (!logFile.is_open()) {
    std::cerr << "Failed to open log file: " << filename << std::endl;
  }
}

void Logger::log(const std::string& message) {
  time_t now = time(nullptr);
  std::string timestamp = ctime(&now);
  timestamp.pop_back(); // remove the newline character at the end
  logFile << "[" << timestamp << "] " << message << std::endl;
}

Logger::~Logger() {
  if (logFile.is_open()) {
    logFile.close();
  }
}
