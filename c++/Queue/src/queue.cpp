#include "queue.hpp"

Queue::Queue() : head(nullptr), tail(nullptr), element_numbers(0) {

}

Queue::~Queue() {

}

void Queue::add(const int &data) {  
  if(this->tail == nullptr) {
    this->tail = new Node(data);
  }else {
    this->tail->next = new Node(data);
    this->tail = this->tail->next;
  }
  if(this->head == nullptr) {
      this->head = this->tail;
  }
  this->element_numbers++;
}

int Queue::remove() {
  int data = this->head->data;
  Node *trash = this->head; 
  this->head = this->head->next;
  if(this->head == nullptr) {
      this->tail = nullptr;
  }
  delete(trash);
  this->element_numbers--;
  return data;
}

bool Queue::contains(const int &data) {
    Node *current = this->head;
    while(current->next != nullptr) {
        if(current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int Queue::size() {
    return this->element_numbers;
}