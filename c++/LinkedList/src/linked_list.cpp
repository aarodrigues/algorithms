#include "linked_list.hpp"

    LinkedList::LinkedList() : head(nullptr), list_lenght(0) {

    }
    
    LinkedList::~LinkedList() {

    }

    void LinkedList::append(const int &data) {
        if(this->head == nullptr) {
            this->head = new Node(data);
            return;
        }
        Node *current = this->head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
        this->list_lenght++;
    }

    void LinkedList::preppend(const int &data) {
        Node *new_head = new Node(data);
        if(this->head == nullptr) {
            this->head = new_head;
            return;
        }
        new_head->next = this->head;
        this->head = new_head;
        this->list_lenght++;
    }

    bool LinkedList::remove_head() {
        Node *trash = this->head;
        this->head = this->head->next;
        delete(trash);
        this->list_lenght--;
        return true;
    }

    bool LinkedList::remove_by_val(const int &data) {
        Node *current = this->head;
        Node *trash;
        while(current->next != nullptr) {
            if(current->next->data == data) {
                trash = current->next;
                current = current->next->next;
            }
            current = current->next;
        }
        delete(trash);
        this->list_lenght--;
        return true;
    }
    
    int LinkedList::size() {
        return this->list_lenght;
    }
