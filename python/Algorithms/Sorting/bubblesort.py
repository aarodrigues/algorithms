class BubbleSort:

    def __init__(self):
        pass

    def sort(self, arr):
        for i in range(0, len(arr)-1):
            for j in range(i+1, len(arr)-1):
                if(arr[i] > arr[j]):
                    temp = arr[i]
                    arr[i] = arr[j]
                    arr[j] = temp
