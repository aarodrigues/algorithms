#include "bubblesort.hpp"
#include <iostream>
#include <string>

BubbleSort::BubbleSort(){

}

BubbleSort::~BubbleSort(){

}

int* BubbleSort::sort(int array[], int size){

    for(unsigned int i = 0; i < size; i++) {

        for (unsigned int j = i+1; j < size; j++)
        {
            if(array[i] > array[j]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return array;
}

void BubbleSort::printArray(int array[], int size) {
    std::string str_arr;
    for (unsigned int i = 0; i < size; i++)
    {
        str_arr.append(" ").append(std::to_string(array[i]));
    }
     std::cout << "{" << str_arr << "}" << std::endl;
}

