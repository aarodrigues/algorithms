#include<iostream>
#include "array_list.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello word" << std::endl;
    ArrayList list;
    list.add(5);
    list.add(10);
    list.add(15);
    list.add(20);
    list.add(25);
    list.add(30);
    list.add(35);
    list.add(40);
    list.add(45);
    list.add(50);
    list.add(55);
    list.add(60);
    list.add(65);
    list.add(70);
    list.add(75);
    std::cout << list.size() << std::endl;

    for(int o = 0; o < 12; o++) {
     std::cout << list.get(o) << std::endl;
    }
    // list.clear();
    std::cout << list.size() << std::endl;

    std::cout << "#######################" << std::endl;

    list.remove_by_val(55);

    for(int o = 0; o < 12; o++) {
     std::cout << list.get(o) << std::endl;
    }

    std::cout << list.size() << std::endl;

    return 0;
}