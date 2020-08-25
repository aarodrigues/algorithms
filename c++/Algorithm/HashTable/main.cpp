#include <iostream>
#include "hashtable.hpp"


int main()
{
    std::cout<<"Hello HashTable!\n";
    HashTable<std::string> ht;
    ht.add("C","Denise");
    ht.add("A","Simone");
    ht.add("D","Carla");

    ht.add("test","caca");
    ht.add("test2","cece");
    ht.add("test3","cici");
    ht.add("test4","coco");
    ht.add("test5","cucu");

    std::cout << ht.get("test5") << std::endl;

    return 0;
}