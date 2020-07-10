#include "binary_tree.hpp"

BinaryTree::BinaryTree() : root(nullptr) {

}

BinaryTree::~BinaryTree() {

}

void BinaryTree::insert(const int &key,const int &data) {
    if(this->root == nullptr) {
        this->root = new Node(key,data);
        return;
    }
    this->insert(this->root, key, data);
}

void BinaryTree::insert(Node *node, const int &key,const int &data) {
    
    std::cout << key << std::endl;
    if(node->key >= key) {
        if(node->left == nullptr) {
           node->left = new Node(key,data);
        }else {
            this->insert(node->left,key,data);
        }
    } else {
        if(node->right == nullptr) {
            node->right = new Node(key,data);
        }else {
            this->insert(node->right,key,data);
        }
    }
}

bool BinaryTree::contains(const int &data) {    
     return this->find(this->root,data);
}

bool BinaryTree::find(Node *node, const int &data) {
    if(node->data == data) {
        return true;
    }
    if(node->data >= data) {
         if(node->left == nullptr) {
             return false;
         }else {
             return this->find(node->left,data);
         }
     }else {
         if(node->right == nullptr) {
             return false;
         }else {
             return this->find(node->right,data);
         }
     }
}

bool BinaryTree::remove(const int &key) {
    if(this->root == nullptr){
        return false;
    }
    this->remove(this->root,key);

}

BinaryTree::Node* BinaryTree::remove(Node *node, const int &key) {
    
    Node *trash = node;
    if(node == nullptr){
        return nullptr;
    }
    if(key < node->key) {
        node->left = this->remove(node->left,key);
    }else if(key > node->key) {
        node->right = this->remove(node->right,key);
    }else{ // found
        // Case 1: No child
        if(node->right == nullptr && node->left == nullptr) {
            trash = node;
            node = nullptr;
        }

        // Case 2: One Child
        else if(node->left == nullptr) {
            trash = node->right;
            node = node->right;
        }else if(node->right == nullptr) {
            trash = node->left;
            node = node->left;
        }

        // Case 3: Two Children
        else {
            Node *min_right = this->min(node);
            node->key = min_right->key;
            node->data = min_right->data;
            node->right = this->remove(node->right, node->key);
        }
        delete(trash);
    }
    return node;
}

void BinaryTree::print() {
    this->printInOrder(this->root);
}

void BinaryTree::printInOrder(Node *node) {
    if(node->left != nullptr){
       this->printInOrder(node->left);
    }
    std::cout << node->data << std::endl;
    if(node->right != nullptr){
        this->printInOrder(node->right);
    }
}

void BinaryTree::printPreOrder(Node *node) {
    std::cout << node->data << std::endl;
    if(node->left != nullptr){
       this->printInOrder(node->left);
    }
    if(node->right != nullptr){
        this->printInOrder(node->right);
    }
}

void BinaryTree::printPosOrder(Node *node) {
    if(node->left != nullptr){
       this->printInOrder(node->left);
    }
    if(node->right != nullptr){
        this->printInOrder(node->right);
    }
    std::cout << node->data << std::endl;
}

BinaryTree::Node* BinaryTree::min() {
    return this->min(this->root);
}

BinaryTree::Node* BinaryTree::min(Node *node) {
    if(node->left == nullptr){
        return node;
    }else {
        this->min(node->left);
    }
}