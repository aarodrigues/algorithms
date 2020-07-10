#include<iostream>

class BinaryTree {
  public:
    class Node {
        public:
          int key;
          int data;
          Node *right, *left;
          Node(const int &key, const int &data) {
              this->key = key;
              this->data = data;
              this->right = nullptr;
              this->left = nullptr;
          }
    };
    Node *root;
    BinaryTree();
    ~BinaryTree();
    void insert(const int &key,const int &data);
    void insert(Node *node,const int &key,const int &data);
    bool contains(const int &data);
    bool find(Node *node, const int &data);
    bool remove(const int &key);
    Node* remove(Node *node, const int &key);
    void print();
    void printInOrder(Node *node);
    void printPreOrder(Node *node);
    void printPosOrder(Node *node);
    Node* min();
    Node* min(Node *node);
};