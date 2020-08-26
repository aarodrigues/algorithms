#include <iostream>

class AVLTree {
    public:
        class Node {
            public:
                int key;
                int value;
                int height;
                Node *left, *right;

                Node(const int &key, const int &value) {
                    this->key = key;
                    this->value = value;
                    this->height = 1;
                    this->left = nullptr;
                    this->right = nullptr;
                }
        };

        Node *root = nullptr;

        void insert(const int &key, const int &value){
            if(root == nullptr) {
                root = new Node(key,value);
                return;
            }
            root = insert(root, key, value);
        }
        
        Node* insert(Node *node, const int &key, const int &value){
            if(node->key > key) {
                if(node->left == nullptr) {
                    node->left = new Node(key, value);
                }else {
                    insert(node->left, key, value);            
                }
            }else if(node->key < key) {
                if(node->right == nullptr) {
                    node->right = new Node(key, value);
                }else {
                    insert(node->right, key, value);            
                }
            }else {
                std::cout << "Duplicated keys is not allowed" << std::endl;
                return node;
            }
        
            node->height = max(height(node->left),height(node->right)) + 1;
            int balance = getBalance(*node);
        
            /**
             * If balance > 1 left branch is bigger 
            */
       
            // left-left case 
            if(balance > 1 && key < node->left->key) {
                std::cout << "rebalanced" << std::endl;
                return rightRotate(node);
            }
            // left-right case
            if(balance > 1 && key > node->left->key) {
                node->left = leftRotate(node);
                return rightRotate(node);
            }
        
            /**
             * If balance < 1 right branch is bigger 
            */
       
            //right-right case
            if(balance < -1 && key > node->right->key) {
                return leftRotate(node);
            }
            // right-left case
            if(balance < -1 && key < node->right->key) {
                node->right = rightRotate(node);
                return leftRotate(node);
            }
        
            return node;
        }
        
        bool remove(const int &key){
            if(root == nullptr) return false;
            remove(*root,key);
        }
        
        bool remove(Node &node, const int &key){
            if(node.key == key) {
                Node *trash = &node;
        
                //Case 1 No child
                if(node.left == nullptr && node.right == nullptr) {
                    delete(trash);
                } 
                
                // Case 2 One child
                else if (node.left == nullptr){
                    trash = node.right;
                    node = *node.right;
                }else if(node.right == nullptr)
                {
                    trash = node.left;
                    node = *node.left;
                }
                
                // Case 3 Two children
                else {
                    Node min = getMin(*node.right);
                    node.key = min.key;
                    node.value = min.value;
                    remove(*node.right, node.key);
                }
                return true;
            }
            
            else if(node.key < key) {
                remove(*node.left, key);
            }else if(node.key > key) {
                remove(*node.right,key);
            }
            return false;
        }
        
        bool find(Node &node, const int &key){
            if(node.key == key) {
                return true;
            }
            if(node.key > key) {
                if(node.left == nullptr) return false;
                find(*node.left,key);
            }else {
                if(node.right == nullptr) return false;
                find(*node.right,key);
            }
        }
        
        bool contains(const int &key){
            return find(*root, key);
        }
        
        void print(){
            printInOrder(*root);
        }
        void printInOrder(Node &node){
            
        
            if(node.left != nullptr){
                printInOrder(*node.left);
            }
            std::cout << node.value << std::endl;
            if(node.right != nullptr) {
                printInOrder(*node.right);
            }
        }
        void printPreOrder(Node &node){
            std::cout << node.key << std::endl;
             if(node.left != nullptr){
                printInOrder(*node.left);
            }
            if(node.right != nullptr) {
                printInOrder(*node.right);
            }
        }
        void printPosOrder(Node &node){
             if(node.left != nullptr){
                printInOrder(*node.left);
            }
            if(node.right != nullptr) {
                printInOrder(*node.right);
            }
            std::cout << node.value << std::endl;
        }
        
        Node getMin(){
           return getMin(*root);
        
        }
        
        Node getMin(Node &node){
           if(node.left == nullptr) {
               return node;
           }else {
               getMin(*node.left);
           }
        }
        
        int height(Node *node) {
            if(node == nullptr) return 0;
            return node->height;
        }
        
        int max(const int &a, const int &b) {
            return (a > b) ? a : b;
        }
        
        int getBalance(Node &node) {
            return height(node.left) - height(node.right);
        }
        
        /*
        * AVL Tree can be rebalance using one of the follows operations
        * Left-left -> Rotate right
        * Right-right -> Rotate left
        * Right-Left -> Rotate right then left 
        * Left-Right -> Rotate left then right
        */
        
        Node* leftRotate(Node *node){
            Node *pivot = node->right;
            Node *p_left_branch = pivot->left;
        
            pivot->left = node;
            node->right = p_left_branch;
        
            node->height = max(node->left->height, node->right->height) + 1;
            pivot->height = max(pivot->left->height, pivot->right->height) + 1;
        
            return pivot;
        }
        
        Node* rightRotate(Node *node){
            Node *pivot = node->left;
            Node *p_right_branch = pivot->right;
        
            pivot->right = node;
            node->left = p_right_branch;
        
            node->height = max(height(node->left),height(node->right)) + 1;
            pivot->height = max(height(pivot->left),height(pivot->right)) + 1;
            
            return pivot;
        }
};