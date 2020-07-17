#include "quicksort.hpp"

QuickSort::QuickSort() {

}

QuickSort::~QuickSort() {

}

int* QuickSort::sort(int array[], int size) {
    this->sort(array,0, size-1);
    return array;
}

void QuickSort::sort(int array[], int low, int high) {
    if(low >= high){
        return;
    }
    int pivot = array[(low+high)/2];
    // Step 2: Partition the array around this pivot - return the index of the partition
    int index = partition(array, low, high, pivot);
    // Step 3: Sort on the left and the right side
    sort(array, low, index - 1);
    sort(array, index, high);
}

int QuickSort::partition(int array[], int low, int high, int pivot) {
    // Move the left and right pointers in towards each other
        while (low <= high) {
            // Move left until you find an element bigger than the pivot
            while(array[low] < pivot) {
                low++;
            }
            // Move right until you find an element smaller than the pivot
            while (array[high] > pivot) {
                high--;
            }
            // Then swap
            if (low <= high) {
                swap(array, low, high);
                low++;
                high--;
            }
        }
        // When we get here, everything in this partition will be in the right order
        // Now we need to return next partition point - which for us will be left
        return low;
}

void QuickSort::swap(int array[], int low, int high) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
}
