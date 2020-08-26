#include <iostream>
#include <sstream>

class BinarySearchTree {
    public:
        int item;
        BinarySearchTree *left,*right;
        int size = 0;

        BinarySearchTree(const int &item) {
            this->item = item;
            this->left = nullptr;
            this->right = nullptr;
        }
        
        BinarySearchTree* min() {
            if(left == nullptr) {
                return this;
            }else {
                return left->min();
            }
        }
        
        void insert(const int &data) {
            if(data < item) {
                if(left == nullptr) {
                    left = new BinarySearchTree(data);
                }else {
                    left->insert(data);
                }
            }else {
                if(right == nullptr) {
                    right = new BinarySearchTree(data);
                }else {
                    right->insert(data);
                }
            }
            size++;
        }

        void remove(const int &data) {
            remove(data,this);
        }
        
        void remove(const int &data, BinarySearchTree *node) {
            if(data < item) {
                node->left->remove(data, node->left);
            }else if(data > item){
                node->right->remove(data, node->right);
            }else {
                //Case One
                if(left == nullptr && right == nullptr) {
                    std::cout << "aqui!!!!! " << node->item << std::endl;
                    delete(node);
                    node = nullptr;
                }
                
                //Case Two
                else if(left == nullptr) {
                    node = right;
                }else if(right == nullptr) {
                    node = left;
                }
                
                //Case Three
                else {
                    BinarySearchTree *min_right = node->right->min();
                    node->item = min_right->item;
                    node->right->remove(node->item, node->right);
                }
            }
        }

        void printInOrder() {
            if(left != nullptr) {
                left->printInOrder();
            }
            std::cout << this->item << std::endl;
            if(right != nullptr) {
                right->printInOrder();
            }
        }
};