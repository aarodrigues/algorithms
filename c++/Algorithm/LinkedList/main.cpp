#include <iostream>
#include "linkedlist.hpp"


int main()
{
    std::cout<<"Hello Linked List!\n";
    LinkedList<std::string> llist;
    llist.add(2,"test1");
    llist.add(4,"test2");
    llist.add(6,"test3");
    llist.add(8,"test4");

    llist.remove(4);

    llist.print();

    return 0;
}