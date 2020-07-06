#include <iostream>

class Stack {
  public:
    class Node {
      public:
        int data;
        Node *next;
        Node(const int &data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    Stack();
    ~Stack();
    void push(const int &data);
    int pop();
    bool contains(const int &data);
    int size();
  private:
    int element_numbers;
    Node *head;
};