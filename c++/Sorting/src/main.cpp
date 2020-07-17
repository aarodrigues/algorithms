#include <iostream>
#include "bubblesort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello world" << std::endl;
    BubbleSort bubblesort;
    MergeSort merge;
    int test[5] = {3,2,5,1,7};
    // int size = sizeof(test)/sizeof(test[0]);
    // std::cout << size << std::endl;
    bubblesort.printArray(test,5);
    // int *result = bubblesort.sort(test,5);
    // bubblesort.printArray(result,5);
    // int *result2 = merge.sort(test,0,4);
    // bubblesort.printArray(result2,5);
    QuickSort quicksort;
    int *result3 = quicksort.sort(test,5);
    bubblesort.printArray(result3,5);

    return 1;
}