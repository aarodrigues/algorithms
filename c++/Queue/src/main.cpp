#include<iostream>
#include "queue.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello World" <<std::endl;
    Queue queue;
    queue.add(35);
    queue.add(42);
    queue.add(3);
    queue.add(65);
    queue.add(15);
    queue.add(6);


    // std::cout << queue.size() << std::endl;
    // std::cout << queue.remove() << std::endl;
    // std::cout << queue.remove() << std::endl;
    // std::cout << queue.size() << std::endl;

    std::cout << queue.contains(5) << std::endl;
    return 0;
}