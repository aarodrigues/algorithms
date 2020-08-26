#include <iostream>

template<class T>
class BinarySearchTree {
    public:
        class Node {
            public:
                int key;
                T value;
                Node *left, *right;

                Node(const int key, const T &value) {
                    this->key = key;
                    this->value = value;
                    this->left = nullptr;
                    this->right = nullptr;
                }

                Node* min() {
                    if(left == nullptr) {
                        return this;
                    }else {
                        return left->min();
                    }
                }
        };

        void insert(const int &key, const T &value) {
            root = insert(key, value, root);
        }

        void remove(const int &key) {
            root = remove(key,root);
        }

        void printInOrder() {
            std::cout <<  "Printing In Order"  << std::endl;
            printInOrder(root);
        }
    
    private:
       Node *root = nullptr;
       int elements_numbers = 0;

       Node* insert(const int &key, const T &value, Node *node) {
            if(node == nullptr) {
                node = new Node(key, value);
            }else if(key < node->key) {
                node->left = insert(key, value, node->left);
            }else if(key > node->key) {
                node->right = insert(key, value, node->right);
            }
            elements_numbers++;
            return node;
        }

        Node* remove(const int &key, Node *node) {
            if(key < node->key) {
                node->left = remove(key,node->left);
            }else if(key > node->key) {
                node->right = remove(key, node->right);
            } else {
                // Case One
                if(node->left == nullptr && node->right == nullptr) {
                    node = nullptr;
                }

                //Case Two
                else if(node->left == nullptr) {
                    node = node->right;
                }else if(node->right == nullptr) {
                    node = node->left;
                }

                //Case Three
                else {
                    Node *min_right = node->right->min();
                    node->key = min_right->key;
                    node->value = min_right->value;
                    node->right = remove(node->key, node->right);
                }
                elements_numbers--;
            }
         return node;
        }

        void printInOrder(Node* node) {
            if(node->left != nullptr) {
                printInOrder(node->left);
            }
            std::cout << node->key << ": " << node->value << std::endl;
            if(node->right != nullptr) {
                printInOrder(node->right);
            }
        }
};
