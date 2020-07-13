#include "max_heap.hpp"
#include <iostream>
#include <string>

MaxHeap::MaxHeap() : array_size(defaut_array_size), size(0) {
    this->items = new int[this->defaut_array_size];
}

MaxHeap::~MaxHeap(){

}

int MaxHeap::extractMax(){
    if(this->size == 0) throw "Empty Heap";
    int item = *(this->items + 0);
    *(this->items + 0) = *(this->items + (size - 1));
    this->size--;
    this->heapifyDown();
    return item;
}

void  MaxHeap::insert(const int &item){
    if(this->size == this->array_size) {
        this->ensureCapacity();
    }
    *(this->items + size) = item;
    this->size++;
    this->heapifyUp();
}

void  MaxHeap::heapifyUp(){
    int index = this->size - 1;
    while (this->hasParent(index) && this->parent(index) < *(this->items + index))
    {
        this->swap(this->parentIndex(index),index);
        index = parentIndex(index);
    }
    
}

void MaxHeap::heapifyDown(){
     int index = 0;

     while(this->hasLeftChild(index)) {
         int largeChildIndex = leftChildIndex(index);

         if(hasRightChild(index) && rightChild(index) > leftChild(index)) {
             largeChildIndex = rightChildIndex(index);
         }

         if(*(items + index) > *(items + largeChildIndex)) {

         }else {
             swap(index, largeChildIndex);
         }
         index = largeChildIndex;
     }
}

void MaxHeap::print(){
    for(int i = 0; i < this->size; i++) {
        std::cout << "Item " << i << std::string(": ") << *(this->items + i) << std::endl;
    }
}

int MaxHeap::leftChildIndex(const int &parentIndex){
    return 2*parentIndex + 1;
}

int MaxHeap::rightChildIndex(const int &parentIndex){
    return 2*parentIndex + 2;
}

int MaxHeap::parentIndex(const int &childIndex){
    return (childIndex - 1) / 2;
}

bool MaxHeap::hasLeftChild(const int &index){
    return leftChildIndex(index) < this->size;
}

bool MaxHeap::hasRightChild(const int &index){
    return rightChildIndex(index) < this->size;
}

bool MaxHeap::hasParent(const int &index){
    return parentIndex(index) >= 0;
}

int MaxHeap::leftChild(const int &index){
    return this->items[leftChildIndex(index)];
}

int MaxHeap::rightChild(const int &index){
    return this->items[rightChildIndex(index)];
}

int MaxHeap::parent(const int &index){
    return this->items[parentIndex(index)];
}

void MaxHeap::ensureCapacity(){
    this->array_size *= 2;
    int *array = new int[this->array_size];
    for(int i = 0; i < this->size; i++) {
        *(array + i) = items[i];
    }
    int *trash = items;
    items = array;
    delete(trash);
}

void MaxHeap::swap(const int &indexOne, const int &indexTwo){
    int temp = *(this->items + indexOne);
    *(this->items + indexOne) = *(this->items + indexTwo);
    *(this->items + indexTwo) = temp;
}

