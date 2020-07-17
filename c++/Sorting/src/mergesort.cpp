#include "mergesort.hpp"
#include <iostream>

MergeSort::MergeSort() {

}

MergeSort::~MergeSort() {

}

int* MergeSort::sort(int array[], int low, int high) {
    if(low < high) {
        int middle = (low+high)/2;
        sort(array,low,middle);
        sort(array,middle+1,high);
        merge(array, low, middle, high);
    }
    return array;
}

void MergeSort::merge(int array[], int low, int middle, int high) {
    int i = low, j = middle+1, k = low;
    int temp[high+1];
    while (i<= middle && j <= high) {
        if(array[i] < array[j]){
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    while (i <= middle) {
        temp[k++] = array[i++];
    }
    while (j <= high) {
        temp[k++] = array[j++];
    }
    for(int i = low; i<= high; i++) {
        array[i] = temp[i];
    }
}

// void MergeSort::merge(int array[], int low, int middle, int high) {
//     int size1 = middle - low + 1;
//     int size2 = high - middle;

//     /* Create temp arrays */
//     int left[size1];
//     int right[size2];
//     /* Copy data to temp arrays */
//     for (int i=0; i<size1; ++i)
//         left[i] = array[low + i];
//     for (int j=0; j<size2; ++j)
//         right[j] = array[middle + 1+ j];
//     /* Merge the temp arrays */
//     // Initial indexes of first and second subarrays
//     int i = 0, j = 0;
//     // Initial index of merged subarry array
//     int k = low;
//     while (i < size1 && j < size2) {
//         if (left[i] <= right[j]) {
//             array[k] = left[i++];
//         }
//         else  {
//             array[k] = right[j++];
//         }
//         k++;
//     }
//     /* Copy remaining elements of L[] if any */
//     while (i < size1)  {
//         array[k++] = left[i++];
//     }
//     /* Copy remaining elements of R[] if any */
//     while (j < size2) {
//         array[k++] = right[j++];
//     } 
// }