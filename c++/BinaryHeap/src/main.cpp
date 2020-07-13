#include "max_heap.hpp"
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "Hello World!!" << std::endl;
    MaxHeap heap;
    heap.insert(42);
    heap.insert(29);
    heap.insert(18);
    heap.insert(35);
    heap.insert(22);
    heap.print();
    return 0;
}