class MaxHeap {
    public:
      int *items;
      static const int defaut_array_size = 10;
      int array_size;
      int size;

      MaxHeap();
      ~MaxHeap();
      int extractMax();
      void insert(const int &item);
      void heapifyUp();
      void heapifyDown();
      void print();

    private:

      /*
      * parent item = (childIndex - 1)/2
      * left child item = 2*parentIndex + 1
      * right child item = 2*parentIndex + 2
      */
      int leftChildIndex(const int &parentIndex);
      int rightChildIndex(const int &parentIndex);
      int parentIndex(const int &childIndex);

      bool hasLeftChild(const int &index);
      bool hasRightChild(const int &index);
      bool hasParent(const int &index);

      int leftChild(const int &index);
      int rightChild(const int &index);
      int parent(const int &index);
      void ensureCapacity();
      void swap(const int &indexOne, const int &indexTwo);
};