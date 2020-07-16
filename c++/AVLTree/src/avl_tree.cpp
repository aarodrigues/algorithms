#include "avl_tree.hpp"


AVLTree::AVLTree() : root(nullptr) {

}

AVLTree::~AVLTree() {
    
}

void AVLTree::insert(const int &key, const int &value){
    if(this->root == nullptr) {
        this->root = new Node(key,value);
        return;
    }
    this->root = this->insert(this->root, key, value);
}

AVLTree::Node* AVLTree::insert(Node *node, const int &key, const int &value){
    if(node->key > key) {
        if(node->left == nullptr) {
            node->left = new Node(key, value);
        }else {
            this->insert(node->left, key, value);            
        }
    }else if(node->key < key) {
        if(node->right == nullptr) {
            node->right = new Node(key, value);
        }else {
            this->insert(node->right, key, value);            
        }
    }else {
        std::cout << "Duplicated keys is not allowed" << std::endl;
        return node;
    }

    node->height = this->max(this->height(node->left),this->height(node->right)) + 1;
    int balance = this->getBalance(*node);

    /**
     * If balance > 1 left branch is bigger 
    */

    // left-left case 
    if(balance > 1 && key < node->left->key) {
        std::cout << "rebalanced" << std::endl;
        return this->rightRotate(node);
    }
    // left-right case
    if(balance > 1 && key > node->left->key) {
        node->left = this->leftRotate(node);
        return this->rightRotate(node);
    }

    /**
     * If balance < 1 right branch is bigger 
    */

    //right-right case
    if(balance < -1 && key > node->right->key) {
        return this->leftRotate(node);
    }
    // right-left case
    if(balance < -1 && key < node->right->key) {
        node->right = this->rightRotate(node);
        return this->leftRotate(node);
    }

    return node;
}

bool AVLTree::remove(const int &key){
    if(this->root == nullptr) return false;
    this->remove(*this->root,key);
}

bool AVLTree::remove(Node &node, const int &key){
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
            Node min = this->getMin(*node.right);
            node.key = min.key;
            node.value = min.value;
            this->remove(*node.right, node.key);
        }
        return true;
    }
    
    else if(node.key < key) {
        this->remove(*node.left, key);
    }else if(node.key > key) {
        this->remove(*node.right,key);
    }
    return false;
}

bool AVLTree::find(Node &node, const int &key){
    if(node.key == key) {
        return true;
    }
    if(node.key > key) {
        if(node.left == nullptr) return false;
        this->find(*node.left,key);
    }else {
        if(node.right == nullptr) return false;
        this->find(*node.right,key);
    }
}

bool AVLTree::contains(const int &key){
    return this->find(*this->root, key);
}

void AVLTree::print(){
    this->printInOrder(*this->root);
}
void AVLTree::printInOrder(Node &node){
    

    if(node.left != nullptr){
        printInOrder(*node.left);
    }
    std::cout << node.value << std::endl;
    if(node.right != nullptr) {
        printInOrder(*node.right);
    }
}
void AVLTree::printPreOrder(Node &node){
    std::cout << node.key << std::endl;
     if(node.left != nullptr){
        printInOrder(*node.left);
    }
    if(node.right != nullptr) {
        printInOrder(*node.right);
    }
}
void AVLTree::printPosOrder(Node &node){
     if(node.left != nullptr){
        printInOrder(*node.left);
    }
    if(node.right != nullptr) {
        printInOrder(*node.right);
    }
    std::cout << node.value << std::endl;
}

AVLTree::Node AVLTree::getMin(){
   return this->getMin(*this->root);

}

AVLTree::Node AVLTree::getMin(Node &node){
   if(node.left == nullptr) {
       return node;
   }else {
       this->getMin(*node.left);
   }
}

int AVLTree::height(Node *node) {
    if(node == nullptr) return 0;
    return node->height;
}

int AVLTree::max(const int &a, const int &b) {
    return (a > b) ? a : b;
}

int AVLTree::getBalance(Node &node) {
    return this->height(node.left) - this->height(node.right);
}

/*
* AVL Tree can be rebalance using one of the follows operations
* Left-left -> Rotate right
* Right-right -> Rotate left
* Right-Left -> Rotate right then left 
* Left-Right -> Rotate left then right
*/

AVLTree::Node* AVLTree::leftRotate(Node *node){
    Node *pivot = node->right;
    Node *p_left_branch = pivot->left;

    pivot->left = node;
    node->right = p_left_branch;

    node->height = this->max(node->left->height, node->right->height) + 1;
    pivot->height = this->max(pivot->left->height, pivot->right->height) + 1;

    return pivot;
}

AVLTree::Node* AVLTree::rightRotate(Node *node){
    Node *pivot = node->left;
    Node *p_right_branch = pivot->right;

    pivot->right = node;
    node->left = p_right_branch;

    node->height = this->max(this->height(node->left),this->height(node->right)) + 1;
    pivot->height = this->max(this->height(pivot->left),this->height(pivot->right)) + 1;
    
    return pivot;
}