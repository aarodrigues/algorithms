class MergeSort {
  public:
    MergeSort();
    ~MergeSort();

    int* sort(int array[], int low, int high);
    void merge(int array[], int low, int middle, int high);
};