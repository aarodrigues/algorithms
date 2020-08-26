#include <iostream>
#include "trie.hpp"


int main()
{
    std::cout<<"Hello Trie!\n";
    Trie trie;
    trie.insert("alano");
    trie.insert("carol");
    trie.insert("julia");

    std::cout << trie.contains("carol") << std::endl;


    return 0;
}