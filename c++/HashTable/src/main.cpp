#include <iostream>
#include "hash_table.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;
    HashTable hashtable;
    hashtable.put("test","caca");
    hashtable.put("test2","cece");
    hashtable.put("test3","cici");
    hashtable.put("test4","coco");
    hashtable.put("test5","cucu");

    std::cout << hashtable.get("test3") << std::endl;
    std::cout << hashtable.get("test4") << std::endl;
    std::cout << hashtable.remove("test4") << std::endl;
    std::cout << hashtable.get("test4") << std::endl;

    return 0;
}