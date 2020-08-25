#include <iostream>

class MaxHeap {
    public:

        int *items;
        static const int defaut_array_size = 10;
        int array_size;
        int size;

        int extractMax(){
            if(this->size == 0) throw "Empty Heap";
            int item = *(this->items + 0);
            *(this->items + 0) = *(this->items + (size - 1));
            this->size--;
            this->heapifyDown();
            return item;
        }

        void  insert(const int &item){
            if(this->size == this->array_size) {
                this->ensureCapacity();
            }
            *(this->items + size) = item;
            this->size++;
            this->heapifyUp();
        }

        void  heapifyUp(){
            int index = this->size - 1;
            while (this->hasParent(index) && this->parent(index) < *(this->items + index))
            {
                this->swap(this->parentIndex(index),index);
                index = parentIndex(index);
            }

        }

        void heapifyDown(){
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

        void print(){
            for(int i = 0; i < this->size; i++) {
                std::cout << "Item " << i << std::string(": ") << *(this->items + i) << std::endl;
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
            return leftChildIndex(index) < this->size;
        }

        bool hasRightChild(const int &index){
            return rightChildIndex(index) < this->size;
        }

        bool hasParent(const int &index){
            return parentIndex(index) >= 0;
        }

        int leftChild(const int &index){
            return this->items[leftChildIndex(index)];
        }

        int rightChild(const int &index){
            return this->items[rightChildIndex(index)];
        }

        int parent(const int &index){
            return this->items[parentIndex(index)];
        }

        void ensureCapacity(){
            this->array_size *= 2;
            int *array = new int[this->array_size];
            for(int i = 0; i < this->size; i++) {
                *(array + i) = items[i];
            }
            int *trash = items;
            items = array;
            delete(trash);
        }

        void swap(const int &indexOne, const int &indexTwo){
            int temp = *(this->items + indexOne);
            *(this->items + indexOne) = *(this->items + indexTwo);
            *(this->items + indexTwo) = temp;
        }
};