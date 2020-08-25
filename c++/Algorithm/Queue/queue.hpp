#include <iostream>
#include <sstream>

template<class T>
class Queue {
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

    void add(const T &item) {
        if(tail == nullptr) {
            tail = new Node(item);
            head = tail;
        }else {
            tail->next = new Node(item);
            tail = tail->next;
        }
        size++;
    }

    T get() {
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
        Node *head = nullptr, *tail = nullptr;
        int size = 0;
};