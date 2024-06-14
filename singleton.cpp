#include <iostream>
#include <mutex>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return *instance;
    }

    // Public method to demonstrate functionality
    void doSomething() {
        std::cout << "Doing something with the singleton instance." << std::endl;
    }

    // Method to destroy the singleton instance (if desired)
    static void destroyInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        delete instance;
        instance = nullptr;
    }

private:
    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton constructor called." << std::endl;
    }

    // Private destructor to control destruction
    ~Singleton() {
        std::cout << "Singleton destructor called." << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static pointer to the singleton instance
    static Singleton* instance;

    // Mutex for thread safety
    static std::mutex mutex;
};

// Initialize static member variables
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main() {
    // Access the singleton instance and call a method
    Singleton& singleton = Singleton::getInstance();
    singleton.doSomething();

    // Optionally destroy the singleton instance (not typical in most singleton patterns)
    // Singleton::destroyInstance();

    return 0;
}
