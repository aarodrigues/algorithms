#include <iostream>
#include <sstream>

template<class T>
class LinkedList {
    public:
        class Node {
            public:
                int key;
                T item;
                Node *next;

                Node(const int &key, const T &item) {
                    this->key = key;
                    this->item = item;
                    this->next = nullptr;
                }
        };

    Node *head = nullptr;
    int size = 0;

    void add(const int &key, const T &item) {
        if(head == nullptr) {
            head = new Node(key,item);
        }else {
            Node *current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(key,item);
        }
        size++;
    }

    void remove(const int &key) {
        Node *current = head;
        Node *trash;
        if(head->key == key) {
            trash = head;
            head = head->next;
            delete(trash);
        }
        while(current->next != nullptr) {
            if(current->next->key == key) {
                trash = current->next;
                current->next = current->next->next;
                delete(trash);
            }
            current = current->next;
        }
        size--;
    }

     void print() {
        Node *current = head;
        std::ostringstream oss;
        while(current->next != nullptr) {
            oss << current->key << " - " << current->item << " | ";
            current = current->next;
        }
        oss << current->key << " - " << current->item;
        std::cout << oss.str() << std::endl;
    }
};