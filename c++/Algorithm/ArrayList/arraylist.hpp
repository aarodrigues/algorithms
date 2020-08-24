#include <iostream>
#include <sstream>

class ArrayList {
    private:
        static const int default_size = 2;
        int *array = new int[default_size];
        int array_size = default_size;
        int elements_numbers = 0;
    
    public:

        void add(const int &item) {
            if(elements_numbers == array_size) {
                resize();
            }
            array[elements_numbers++] = item; 
        }

        int get(const int &index) {
            return array[index];
        }

        void remove(const int &index) {
            for(int i = index; i < elements_numbers; i++) {
                array[i] = array[i+1];
            }
            elements_numbers--;
        }

        void resize() {
            array_size *= 2;
            int *temp = new int[array_size];
            for(int i = 0; i < elements_numbers; i++) {
                temp[i] = array[i];
            }
            delete(array);
            array = temp;
        }

        int size() {
            return elements_numbers;
        }

        void clear() {
            delete(array);
            elements_numbers = 0;
            array_size = default_size;
            array = new int[default_size];
        }
};