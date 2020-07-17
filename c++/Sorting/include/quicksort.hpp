
class QuickSort {
    public:
      QuickSort();
      ~QuickSort();

      int* sort(int array[], int size);
      void sort(int array[], int low, int high);
      int partition(int array[], int low, int high, int pivot);
      void swap(int array[], int low, int high);
};