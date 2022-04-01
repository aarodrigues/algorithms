class MaxHeap:
    def __init__(self):
        self.capacity = 10
        self.array = self.capacity*[None]
        self.size = 0

    def get_left_child_index(self, index):
        return index*2+1

    def get_right_child_index(self, index):
        return index*2+2

    def get_parent_index(self, index):
        return int((index-1)/2)

    def has_left_child(self, index):
        return self.get_left_child_index(index) < self.size

    def has_right_child(self, index):
        return self.get_right_child_index(index) < self.size

    def has_parent(self, index):
        return self.get_parent_index(index) >= 0

    def left_child(self, index):
        return self.array[self.get_left_child_index(index)]

    def right_child(self, index):
        return self.array[self.get_right_child_index(index)]

    def parent(self, index):
        return self.array[self.get_parent_index(index)]

    def ensure_capacity(self):
        if(self.capacity == self.size):
            self.capacity *=2
            temp = self.capacity*[None]
            for i in range(0, self.size):
                temp[i] = self.array[i]
            self.array = temp

    def swap(self, index_one, index_two):
        temp = self.array[index_one]
        self.array[index_one] = self.array[index_two]
        self.array[index_two] = temp

    def heapify_up(self):
        index = self.size-1
        while(self.has_parent(index) and self.array[self.get_parent_index(index)] < self.array[index]):
            self.swap(index, self.get_parent_index(index))
            index = self.get_parent_index(index)
    
    def heapify_down(self):
        index = 0
        greater_index = self.get_left_child_index(index)
        while(self.has_right_child(index)):
            if(self.left_child(index) < self.right_child(index)):
                greater_index = self.get_right_child_index(index)
            if(self.array[index] > self.array[greater_index]):
                break
            else:
                self.swap(index, greater_index)
            index = greater_index

    def add(self, item):
        self.ensure_capacity()
        self.array[self.size] = item
        self.size +=1
        self.heapify_up()

    def get_max(self):
        if(self.size == 0): Exception("Empty Heap!")
        return self.array[0]

    def extract_max(self):
        if(self.size == 0): Exception("Empty Heap!")
        item = self.array[0]
        self.array[0] = self.array[self.size-1]
        self.array[self.size-1] = None
        self.size -=1
        self.heapify_down()
        return item

    def show(self):
        for i in range(0, self.size):
            print(self.array[i])

if __name__ == '__main__':
    maxHeap = MaxHeap()
    maxHeap.add(1)
    maxHeap.add(4)
    maxHeap.add(2)
    maxHeap.add(3)
    maxHeap.show()
    print("########## max item: "+str(maxHeap.get_max()))
    
    print("########## removed max item: "+str(maxHeap.extract_max()))
    print("########## removed max item: "+str(maxHeap.extract_max()))
    maxHeap.show()