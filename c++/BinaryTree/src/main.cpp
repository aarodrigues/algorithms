#include <iostream>
#include "binary_tree.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello World" << std::endl;
    BinaryTree tree;
    tree.insert(2,10);
    tree.insert(1,10);
    tree.insert(4,20);
    tree.insert(3,30);
    tree.insert(9,40);
    tree.insert(5,50);
    tree.insert(15,120);
    tree.print();
    BinaryTree::Node *min = tree.min();
    std::cout << min->key << std::endl;

    return 0;
}