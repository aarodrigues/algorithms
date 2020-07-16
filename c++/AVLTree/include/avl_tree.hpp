
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
    
    AVLTree();
    ~AVLTree();
    void insert(const int &key, const int &value);
    AVLTree::Node* insert(Node *node, const int &key, const int &value);
    bool remove(const int &key);
    bool remove(Node &node, const int &key);
    bool find(Node &node, const int &key);
    bool contains(const int &key);
    void print();
    void printInOrder(Node &node);
    void printPreOrder(Node &node);
    void printPosOrder(Node &node);
    Node getMin();
    int height(Node *node);
    int max(const int &a, const int &b);
    int getBalance(Node &node);

  private:
    Node *root;
    Node* leftRotate(Node *node);
    Node* rightRotate(Node *node);
    Node getMin(Node &node);
};