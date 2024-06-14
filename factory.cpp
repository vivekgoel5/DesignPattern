// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream> 
// Logger interface
class ILogger {
 public:
  virtual void Log(const std::string& message) = 0;
};

// Logger types
class ConsoleLogger : public ILogger {
 public:
  void Log(const std::string& message) override {
    std::cout << message << std::endl;
  }
};

class FileLogger : public ILogger {
 public:
  FileLogger(const std::string& filename) : filename_(filename) {}

  void Log(const std::string& message) override {
    std::ofstream file(filename_, std::ios::app);
    file << message << std::endl;
  }

 private:
  std::string filename_;
};

// Logger factory
class LoggerFactory {
 public:
  static ILogger* CreateLogger(const std::string& type) {
    if (type == "console") {
      return new ConsoleLogger();
    } else if (type == "file") {
      return new FileLogger("log.txt");
    } else {
      return nullptr;
    }
  }
};

// Usage
int main() {
  // Create a logger
  ILogger* logger = LoggerFactory::CreateLogger("console");

  // Log a message
  logger->Log("Hello, world!");

  // Delete the logger
  delete logger;

  return 0;
}
