#include <iostream>
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "radixsort.hpp"
#include "bubblesort.hpp"


int main()
{
    int array[10] = {432,8,530,90,88,231,11,45,677,199};

    std::cout<<"Hello BubbleSort!\n";
    BubbleSort bsort;
    bsort.sort(array,10);
    bsort.print(array,10);

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