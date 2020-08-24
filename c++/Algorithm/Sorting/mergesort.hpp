#include <iostream>
#include <sstream>

class MergeSort {
    public:

        void merge(int *array, const int &left, const int &right, const int &m_index) {
            int i = left, j = m_index+1, k = left;
            int temp[right+1];

            while(i <= m_index && j <= right) {
                if(array[i] < array[j]) {
                    temp[k++] = array[i++];
                }else {
                    temp[k++] = array[j++];
                }
            }

            while(i <= m_index) {
                temp[k++] = array[i++];
            }

            while(j <= right) {
                temp[k++] = array[j++];
            }

            for(int i = left; i <= right; i++) {
                array[i] = temp[i];
            }
        }

        void mergesort(int *array, const int left, const int &right) {
            if(left >= right)
                return;
            int m_index = (left+right)/2;
            mergesort(array, left, m_index);
            mergesort(array, m_index+1, right);
            merge(array,left,right,m_index);
        }

        void sort(int *array, const int &size) {
            mergesort(array, 0, size-1);
        }

        void print(int *array, const int &size) {
            std::ostringstream oss;
            for(int i=0; i<size; i++) {
                oss << array[i] << " ";
            }
            std::cout << oss.str() << std::endl;
        }
};
