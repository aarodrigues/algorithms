#include "hash_table.hpp"
#include <bitset>


HashTable::HashTable() : array_size(default_size), element_numbers(0) {

}

HashTable::~HashTable() {

}

void HashTable::put(const std::string &key, const std::string &value) {
  int idx = this->get_index(key);
  HashEntry *entry = new HashEntry(key,value);
  if(this->data[idx] == nullptr) {
      this->data[idx] = entry;
  }else {
      HashEntry *current = this->data[idx];
      while(current->next != nullptr) {
          current = current->next;
      }
      current->next = entry;
  }
  this->element_numbers++;
}

std::string HashTable::get(const std::string &key) {
  int idx = this->get_index(key);
  HashEntry *entries = this->data[idx];
  if(entries != nullptr) {
      while (!entries->key.compare(key) == 0 && entries->next != nullptr) {
          entries = entries->next;
      }
      return entries->value;
  }
  return std::string("Not Found");
}


bool HashTable::remove(const std::string &key) {
  int idx = this->get_index(key);
  HashEntry *entries = this->data[idx];
  if(entries != nullptr) {
      if(entries->key.compare(key) == 0) {
        delete(this->data[idx]);
        this->data[idx] = nullptr;
        return true;
      }else {
        while (!entries->next->key.compare(key) == 0 && entries->next != nullptr) {
            if(entries->key.compare(key) == 0) {
              delete(this->data[idx]);
              this->data[idx] = nullptr;
              return true;
            }
            entries = entries->next;
        }
      }
  }
  return false;
}

int HashTable::get_index(const std::string &key) {
  std::hash<std::string> hash_str;
  std::size_t hash = hash_str(key);
  return hash%this->array_size;
}
