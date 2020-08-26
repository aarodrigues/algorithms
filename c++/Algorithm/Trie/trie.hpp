#include <iostream>
#include <map>

class Trie {
    public:
        class Node {
            public:
                char character;
                bool complete_word;
                std::map<char,Node*> *children;

                Node(const char &character) {
                    this->character = character;
                    this->children = new std::map<char,Node*>();
                }

                Node() {
                    this->children = new std::map<char,Node*>();
                }
        };

        void insert(const std::string &word) {
            
            std::map<char,Node*> *currentMapNode = root->children;
            Node *trieNode = nullptr;
            for(unsigned i = 0; i < word.length(); i++) {
                char character = word.at(i);
                std::map<char,Node*>::iterator it = currentMapNode->find(character);
                if(it != currentMapNode->end()) {
                   //element found;
                   trieNode = it->second;
                }else {
                   trieNode = new Node(character);
                   currentMapNode->insert(std::pair<char,Node*>(character, trieNode));
                }
                currentMapNode = trieNode->children;

                if(i == word.length() - 1) {
                    trieNode->complete_word = true;
                } 
            }
        }

        bool contains(const std::string &word) {
            Node *trieNode = getNode(word);
            return (trieNode != nullptr && trieNode->complete_word);
        }

        bool startsWith(const std::string &prefix) {
            return getNode(prefix) != nullptr;
        }

    private:
        Node *root = new Node();

        Node* getNode(const std::string &word) {
            std::map<char, Node*> *currentMapNode = root->children;
            Node *trieNode = nullptr;
            for(int i = 0; i < word.length(); i++){
                char character = word.at(i);
                std::map<char,Node*>::iterator it = currentMapNode->find(character);
                if(it != currentMapNode->end()) {
                       //element found;
                       trieNode = it->second;
                       currentMapNode = trieNode->children;
                }else {
                    return nullptr;
                }
            }
            return trieNode;
        }
};