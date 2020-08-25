#include <iostream>
#include "stack.hpp"


int main()
{
    std::cout<<"Hello Stack!\n";
    Stack<int> stack;
    stack.put(2);
    stack.put(4);
    stack.put(6);
    stack.put(8);
    std::cout << stack.pop() << std::endl;
    stack.print();

    return 0;
}