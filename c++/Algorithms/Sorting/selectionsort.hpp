#include <iostream>
#include <sstream>

class SelectionSort {
      public:
        
        void sort(int *array, const int &size) {
            int k;

            for(int i = 0; i < size-1; i++) {
                for(int j = k = i; j< size; j++) {
                    if(array[j] < array[k]) {
                        k = j;
                    }
                }
                int temp  = array[i];
                array[i] = array[k];
                array[k] = temp;
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