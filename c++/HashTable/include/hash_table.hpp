#include <iostream>
#include <string>

class HashTable {
  public:
    class HashEntry {
      public:
        std::string key;
        std::string value;
        HashEntry *next;
        HashEntry(const std::string &key, const std::string &value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };
    HashTable();
    ~HashTable();
    void put(const std::string &key, const std::string &value);
    std::string get(const std::string &key);
    int get_index(const std::string &key);
    bool remove(const std::string &key);

  private:
    int element_numbers;
    static const int default_size = 10;
    int array_size;
    HashEntry *data[default_size] = {nullptr};
};