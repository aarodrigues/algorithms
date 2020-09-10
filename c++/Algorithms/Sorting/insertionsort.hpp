#include <iostream>
#include <sstream>

class InsertionSort {
      public:
        void sort(int *array, const int &size) {
            int j, temp;
            for (int i = 1; i < size; i++) {
                j = i -1;
                temp = array[i];
                while(j > -1 && array[j] > temp) {
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = temp;
            }
        }

        void print(int *array, const int &size) {
            std::ostringstream oss;
            for (int i = 0; i < size; i++) {
                oss << array[i] << " ";
            }
            std::cout << oss.str() << std::endl;
        }
};