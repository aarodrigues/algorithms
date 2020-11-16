class MergeSort:
    def __init__(self):
        pass

    def merge(self, arr, left, right, index):
        i = left
        j = index +1
        k = left
        temp = []

        while(i <= index and j <= right):
            if(arr[i] < arr[j]):
                temp[k] = arr[i]
                k += 1
                i += 1
            else:
                temp[k] = arr[j]
                k += 1
                j += 1

        while(i <= index):
            temp[k] = arr[i]
            k += 1
            i += 1

        while(j <= right):
            k += 1
            j += 1
        
        for i in range(left, right):
            arr[i] = temp[i]


    def mergesort(self, arr, left, right):
        if(left >= right):
            return

        index = int((left+right)/2)
        self.mergesort(arr, left, index)
        self.mergesort(arr, index+1, right)
        self.merge(arr, left, right, index)

    def sort(self, arr):
        self.mergesort(arr, 0, len(arr)-1)