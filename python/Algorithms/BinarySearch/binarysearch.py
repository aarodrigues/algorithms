class BinarySearch:
    def __init__(self):
        pass

    def search(self, array, item):
        # return self.recursively_search(array, item, 0, len(array)-1)
        return self.interactive_search(array, item, 0, len(array)-1)

    def recursively_search(self, array, item, left, right):
        if(left > right):
            return -1
        mid = int((left+right)/2)
        if(item < array[mid]):
            return self.recursively_search(array, item, left, mid - 1)
        elif(item > array[mid]):
            return self.recursively_search(array, item, mid + 1, right)
        else:
            return mid

    def interactive_search(self, array, item, left, right):
            
        while(left <= right):
            mid = int((left+right)/2)
            
            if(item > array[mid]):
                left = mid + 1
            elif(item < array[mid]):
                right = mid - 1
            else:
                return mid
        return -1

if __name__ == '__main__':
    array = [ 3, 4, 5, 7, 12, 14, 18, 21, 35, 38, 44, 53, 67]
    bs = BinarySearch()
    print(bs.search(array, 44))