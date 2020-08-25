#include <iostream>
#include "queue.hpp"


int main()
{
    std::cout<<"Hello Queue!\n";
    Queue<int> queue;
    queue.add(2);
    queue.add(4);
    queue.add(6);
    queue.add(8);
    std::cout << queue.get() << std::endl;
    queue.print();

    return 0;
}