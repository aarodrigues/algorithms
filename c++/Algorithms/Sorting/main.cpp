#include <iostream>
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "radixsort.hpp"
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"


int main()
{
    int array[10] = {432,8,530,90,88,231,11,45,677,199};

    std::cout<<"Hello SelectionSort!\n";
    SelectionSort selection;
    selection.sort(array,10);
    selection.print(array, 10);

    // std::cout<<"Hello InsertSort!\n";
    // InsertionSort insertion;
    // insertion.sort(array,10);
    // insertion.print(array, 10);

    // std::cout<<"Hello BubbleSort!\n";
    // BubbleSort bsort;
    // bsort.sort(array,10);
    // bsort.print(array,10);

    // std::cout<<"Hello RadixSort!\n";
    // MergeSort rsort;
    // rsort.sort(array,10);
    // rsort.print(array,10);

    // std::cout<<"Hello MergeSort!\n";
    // MergeSort msort;
    // msort.sort(array,10);
    // msort.print(array,10);


    // std::cout<<"Hello QuickSort!\n";
    // QuickSort qsort;
    // qsort.sort(array,10);
    // qsort.print(array,10);
    

    return 0;
}