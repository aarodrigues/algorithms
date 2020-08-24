#include <iostream>
#include "binarysearchtree.hpp"


int main()
{
    std::cout<<"Hello Binary Search Tree!\n";
    BinarySearchTree<std::string> bst;
    bst.insert(5,"uiii");
    bst.insert(2,"aiii");
    bst.insert(4,"eeii");
    bst.insert(6,"oraora");
    bst.remove(5);
    bst.printInOrder();

    return 0;
}