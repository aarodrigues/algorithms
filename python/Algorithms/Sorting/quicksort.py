class QuickSort:

    def __init__(self):
        pass

    def partition(self, arr, left, right, pivot):
        while(left <= right):
            while(arr[left] < pivot):
                left += 1
            while(arr[right] > pivot):
                right -= 1

            if(left <= right):
                temp = arr[left]
                arr[left] = arr[right]
                arr[right] = temp
                left += 1
                right -= 1
        
        return left
        

    def quicksort(self, arr, left, right):
        if(left >= right):
            return

        pivot = arr[int((left+right)/2)]
        index = self.partition(arr, left, right, pivot)
        self.quicksort(arr, left, index-1)
        self.quicksort(arr, index, right)
    
    def sort(self, arr):
        self.quicksort(arr, 0, len(arr)-1)
    

