#include <iostream>
#include <sstream>

class QuickSort {
    public:

        int partition(int *array, int left, int right, int pivot) {
            while(left <= right) {
                while(array[left] < pivot) {
                    left++;
                }

                while(array[right] > pivot) {
                    right--;
                }

                if(left <= right) {
                    int temp = array[left];
                    array[left] = array[right];
                    array[right] = temp;
                    left++;
                    right--;
                }
            }
            return left;
        }

        void quicksort(int *array, const int &left, const int &right) {
            if(left >= right)
                return;

            int pivot = array[(left+right)/2];
            int index = partition(array, left, right, pivot);

            quicksort(array, left, index-1);
            quicksort(array, index, right);
        }

        void sort(int *array, const int &size) {
            quicksort(array, 0, size-1);
        }

        void print(int *array, const int &size) {
            std::ostringstream oss;
            for(int i=0; i<size; i++) {
                oss << array[i] << " ";
            }
            std::cout << oss.str() << std::endl;
        }
};