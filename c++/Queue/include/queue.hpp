#include <iostream>

class Queue {
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

    Queue();
    ~Queue();
    void add(const int &data);
    int remove();
    bool contains(const int &data);
    int size();

  private:
    int element_numbers;
    Node *head;
    Node *tail;
};