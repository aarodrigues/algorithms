#include "array_list.hpp"

    ArrayList::ArrayList() : elemet_numbers(0), last_element(-1) {
        this->array = new int[this->defaut_size];
        this->slot_size = this->defaut_size;
    }

    ArrayList::~ArrayList() {
        delete(this->array);
    }

    void ArrayList::add(const int &index, const int &value) {
        if(index > this->slot_size) {
            this->resize();
        }
        if(this->last_element < index) this->last_element = index;
        *(this->array + index) = value;
        this->elemet_numbers++;
    }

    int ArrayList::get(const int &index) {
        if(index > this->elemet_numbers) throw std::out_of_range ("Out of bounds");
        return *(this->array + index);
    }

    void ArrayList::add(const int &value) {
        if(this->last_element == this->slot_size - 1) {
            this->resize();
        }
        if(this->last_element == -1) {
           *(this->array) = value;
        }else {
           *(this->array + this->last_element + 1) = value;
        }
        this->last_element = this->last_element + 1;
         
        this->elemet_numbers++;
    }

    bool ArrayList::remove_by_val(const int &value) {
        bool found = false;
        for(int i = 0; i < this->elemet_numbers; i++){
            if(*(this->array + i) == value) {
                found = true;
            }
            if(found) {
              *(this->array + i) = *(this->array + i + 1);
            }
        }
        this->elemet_numbers--;
        return found;
    }

    bool ArrayList::remove(const int &index) {
        if(index > this->last_element) return false;
        for(int i = index; i < this->elemet_numbers; i++){
            *(this->array + i-1) = *(this->array + i);
        }
        this->elemet_numbers--;
        return true;
    }

    int ArrayList::size() {
        return this->elemet_numbers;
    }

    void ArrayList::resize() {
        int lengh = this->slot_size*2;
        int *new_array = new int[lengh];
        for(int i = 0; i < this->slot_size; i++) {
            *(new_array + i) = *(this->array + i);
        }
        delete(this->array);
        this->array = new_array;
        this->slot_size = lengh;
    }

    void ArrayList::clear() {
        delete(this->array);
        this->array = new int[defaut_size];
        this->elemet_numbers = 0;
        this->last_element = -1;
        this->slot_size = defaut_size;
    }

    bool ArrayList::contains(const int &value) {
        for(int i = 0; i < this->last_element; i++){
            if(*(this->array + i) == value) {
                return true;
            }
        }
        return false;
    }