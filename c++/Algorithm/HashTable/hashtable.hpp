#include <iostream>
#include <sstream>
#include <bitset>

template<class T>
class HashTable {
    public:
        class Node {
            public:
                std::string key;
                T value;
                Node *next;

                Node(const std::string &key, const T &value) {
                    this->key = key;
                    this->value = value;
                    this->next = nullptr;
                }
        };

    static const int default_value = 10; 
    Node *array[default_value] = {nullptr};
    int array_size = default_value;
    int elements_numbers = 0;

    int getIndex(const std::string &key) {
        std::hash<std::string> str_hash;
        std::size_t hash = str_hash(key);
        return hash % array_size;
    }

    void add(const std::string &key, T value) {
        int index = getIndex(key);
        if(array[index] == nullptr) {
            array[index] = new Node(key, value);
        }else {
            Node *current = array[index];
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(key, value);
        }
        elements_numbers++;
    }

    T get(const std::string &key) {
        int index = getIndex(key);
        if(array[index] != nullptr) {
            if(array[index]->key.compare(key) == 0) {
                return array[index]->value;
            }else {
                Node *current = array[index];
                while(current->next != nullptr) {
                    if(current->key.compare(key) == 0) {
                        return current->value;
                    }
                    current = current->next;
                }
            }
        }
        return std::string("Not found!");
    }

    void remove(const std::string &key) {
        int index = getIndex(key);
        if(array[index] == nullptr)
            return;

        Node* trash;
        if(array[index]->key.compare(key) == 0) {
            trash = array[index];
            array[index] = array[index]->next;
        }else {
            Node *current = array[index];
            while(current->next != nullptr) {
                if(current->key.compare(key) == 0) {
                    trash = current;
                    current = current->next;
                }
                current = current->next;
            }
        }
        delete(trash);
        elements_numbers--;
    }
};