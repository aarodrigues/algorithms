#include <iostream>
#include <sstream>

class RadixSort {
    public:
        int radix_array[10];
        
        int getMax(int *array, const int &size) {
            int max = array[0];
            for(int i = 0;i<size;i++) {
                if(array[i] > max) {
                    max = array[i];
                }
            }
            return max;
        }
        
        void countsort(int *array, const int &size, const int &pos) {
            int count[10] = {0};
            int digits = 10;
            int array_sorted[size];
            
            for(int i = 0; i < size; i++){
                ++count[(array[i]/pos)%10];
            }
            for(int i = 1; i < digits; i++) {
                count[i] = count[i] + count[i-1];
            }
            for(int i = size-1; i >= 0; i--) {
                array_sorted[--count[(array[i]/pos)%10]] = array[i];
            }
            
            for(int i = 0;i <size; i++) {
                array[i] = array_sorted[i];
            }
        }
    
        void radixsort(int *array, const int &size) {
            int max = getMax(array,size);
            for(int pos=1; (max/pos) > 0; pos*=10){
                countsort(array, size, pos);
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