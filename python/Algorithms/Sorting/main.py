import quicksort
import bubblesort
import mergesort


def print_arr(arr):
    str_arr = ""
    for item in arr:
        str_arr += str(item) + " "
    print(str_arr)


if __name__ == "__main__":
    array = [9,8,3,4,6,5,2,7,1,10]
    # quick = quicksort.QuickSort()
    # quick.sort(array)
    # bubble = bubblesort.BubbleSort()
    # bubble.sort(array)
    merge = mergesort.MergeSort()
    merge.sort(array)
    print_arr(array)