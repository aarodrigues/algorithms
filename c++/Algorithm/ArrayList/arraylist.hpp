#include <iostream>
#include <sstream>

template<class T>
class ArrayList {
    private:
        static const int default_size = 2;
        T *array = new T[default_size];
        int array_size = default_size;
        int elements_numbers = 0;
    
    public:

        void add(const T &item) {
            if(elements_numbers == array_size) {
                resize();
            }
            array[elements_numbers++] = item; 
        }

        T get(const int &index) {
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
            T *temp = new T[array_size];
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
            array = new T[default_size];
        }
};