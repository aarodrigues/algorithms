class MergeSort:
    
    def __init__(self):
        pass
    
    def sort(self, arr):
        self.mergesort(arr, 0, len(arr)-1)
        
        
    def mergesort(self, arr, left, right):
        if(left >= right):
            return
        
        mid = int((left+right)/2)
        
        self.mergesort(arr, left, mid)
        self.mergesort(arr, mid+1, right)
        self.merge(arr,left, right, mid)
        
    def merge(self, arr, left, right, mid):
        i = left
        j = mid+1
        k = left

        temp = [0 for i in range(right+1)]
        
        while(i <= mid and j <= right):
            if(arr[i] < arr[j]):
                temp[k] = arr[i]
                k += 1
                i += 1
            else:
                temp[k] = arr[j]
                k += 1
                j += 1
        
        while(i <= mid):
            temp[k] = arr[i]
            k += 1
            i += 1
            
        while(j <= right):
            temp[k] = arr[j]
            k += 1
            j += 1
            
        for i in range(left, right+1):
            arr[i] = temp[i]

            