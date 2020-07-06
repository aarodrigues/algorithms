#include <iostream> 
#include "stack.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello World" << std::endl;
    Stack stack;

    stack.push(35);
    stack.push(42);
    stack.push(3);
    stack.push(65);
    stack.push(15);
    stack.push(6);

    std::cout << stack.size() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.size() << std::endl;

    // std::cout << stack.contains(65) << std::endl;

    return 0;
}