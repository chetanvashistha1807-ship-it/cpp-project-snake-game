#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Thread library works!";
    return 0;
}
