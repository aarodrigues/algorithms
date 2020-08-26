#include <iostream>

class MaxHeap {
    public:

        int *items;
        static const int defaut_array_size = 10;
        int array_size;
        int size;

        int extractMax(){
            if(size == 0) throw "Empty Heap";
            int item = items[0];
            items[0] = items[size - 1];
            size--;
            heapifyDown();
            return item;
        }

        void  insert(const int &item){
            if(size == array_size) {
                ensureCapacity();
            }
            items[size++] = item;
            heapifyUp();
        }

        void  heapifyUp(){
            int index = size - 1;
            while (hasParent(index) && parent(index) < items[index])
            {
                swap(parentIndex(index),index);
                index = parentIndex(index);
            }

        }

        void heapifyDown(){
             int index = 0;

             while(hasLeftChild(index)) {
                 int largeChildIndex = leftChildIndex(index);

                 if(hasRightChild(index) && rightChild(index) > leftChild(index)) {
                     largeChildIndex = rightChildIndex(index);
                 }

                 if(items[index] > items[largeChildIndex]) {
                 
                 }else {
                     swap(index, largeChildIndex);
                 }
                 index = largeChildIndex;
             }
        }

        void print(){
            for(int i = 0; i < size; i++) {
                std::cout << "Item " << i << std::string(": ") << items[i] << std::endl;
            }
        }

        int leftChildIndex(const int &parentIndex){
            return 2*parentIndex + 1;
        }

        int rightChildIndex(const int &parentIndex){
            return 2*parentIndex + 2;
        }

        int parentIndex(const int &childIndex){
            return (childIndex - 1) / 2;
        }

        bool hasLeftChild(const int &index){
            return leftChildIndex(index) < size;
        }

        bool hasRightChild(const int &index){
            return rightChildIndex(index) < size;
        }

        bool hasParent(const int &index){
            return parentIndex(index) >= 0;
        }

        int leftChild(const int &index){
            return items[leftChildIndex(index)];
        }

        int rightChild(const int &index){
            return items[rightChildIndex(index)];
        }

        int parent(const int &index){
            return items[parentIndex(index)];
        }

        void ensureCapacity(){
            array_size *= 2;
            int *array = new int[array_size];
            for(int i = 0; i < size; i++) {
                array[i] = items[i];
            }
            int *trash = items;
            items = array;
            delete(trash);
        }

        void swap(const int &indexOne, const int &indexTwo){
            int temp = items[indexOne];
            items[indexOne] = items[indexTwo];
            items[indexTwo] = temp;
        }
};