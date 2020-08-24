#include <iostream>
#include <sstream>

class BubbleSort {
    public:

        void sort(int *array, const int &size) {
            for(int i = 0; i < size; i++) {
                for(int j = i+1; j < size; j++) {
                    if(array[i] > array[j]) {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
        }

        void print(int *array, const int &size) {
            std::ostringstream oss;
            for(int i=0; i<size; i++) {
                oss << array[i] << " ";
            }
            std::cout << oss.str() << std::endl;
        }
};