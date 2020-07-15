#include <iostream>
#include "avl_tree.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello Word" << std::endl;
    AVLTree tree;
    tree.insert(3,51);
    tree.insert(2,52);
    tree.insert(1,53);
    tree.print();

    return 0;
}