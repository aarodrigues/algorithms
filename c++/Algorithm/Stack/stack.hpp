#include <iostream>
#include <sstream>

template<class T>
class Stack {
    public:
        class Node {
            public:
                T item;
                Node *next;

                Node(const T &item) {
                    this->item = item;
                    this->next = nullptr;
                }
        };

    void put(const T &item) {
        if(head == nullptr) {
            head = new Node(item);
        }else {
            Node *node = new Node(item);
            node->next = head;
            head = node;
        }
        size++;
    }

    T pop() {
        if(head != nullptr) {
            T item = head->item;
            Node *trash = head;
            head = head->next;
            delete(trash);
            size--;
            return item;
        }
    }

    void print() {
        Node *current = head;
        std::ostringstream oss;
        while(current->next != nullptr) {
            oss << current->item << " ";
            current = current->next;
        }
        oss << current->item;
        std::cout << oss.str() << std::endl;
    }

    int lengh() {
        return size;
    }

    private:
        Node *head = nullptr;
        int size = 0;
};