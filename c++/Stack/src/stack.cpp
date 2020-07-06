#include "stack.hpp"

Stack::Stack() : head(nullptr), element_numbers(0){

}
Stack::~Stack() {

}
void Stack::push(const int &data) {
  if(this->head == nullptr) {
    this->head = new Node(data);
  }
  Node *new_item = new Node(data);
  new_item->next = this->head;
  this->head = new_item;
  this->element_numbers++;
}
int Stack::pop() {
    int data = this->head->data;
    Node *trash = this->head;
    this->head = this->head->next;
    delete(trash);
    this->element_numbers--;
    return data;
}
bool Stack::contains(const int &data){
    Node *current = this->head;
    while (current->next != nullptr)
    {
        if(current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}
int Stack::size(){
    return this->element_numbers;
}