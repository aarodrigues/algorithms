class minHeap:
    def __init__(self):
        self.capacity = 10
        self.size = 0
        self.array = self.capacity*[None]

    # Get indexes
    def get_left_child_index(self, parent_index):
        return  2 * parent_index + 1
    
    def get_right_child_index(self, parent_index):
        return  2 * parent_index + 2

    def get_parent_index(self, child_index):
        return int((child_index -1) / 2)

    # Has item
    def has_left_child(self, index):
        return self.get_left_child_index(index) < self.size

    def has_right_child(self, index):
        return self.get_right_child_index(index) < self.size

    def has_parent(self, index):
        return self.get_parent_index(index) >= 0

    # Get items
    def left_child(self, index):
        return self.array[self.get_left_child_index(index)]

    def right_child(self, index):
        return self.array[self.get_right_child_index(index)]

    def parent(self, index):
        return self.array[self.get_parent_index(index)]

    # Manage Heap
    def swap(self, index_one, index_two):
        temp = self.array[index_one]
        self.array[index_one] = self.array[index_two]
        self.array[index_two] = temp

    def ensure_capacity(self):
        self.capacity *=2
        new_array = self.size*[None]
        for i in range(0,self.size):
            new_array[i] = self.array[i]
        self.array = new_array

    def heapify_up(self):
        index = self.size -1

        while(self.has_parent(index) and self.parent(index) > self.array[index]):
            self.swap(self.get_parent_index(index), index)
            index = self.get_parent_index(index)

    def heapify_down(self):
        index = 0
        while(self.has_left_child(index)):
            smaller_child_idx = self.get_left_child_index(index)
            if(self.has_right_child(index) and self.right_child(index) < self.left_child(index)):
                smaller_child_idx = self.get_right_child_index(index)
            if(self.array[index] < self.array[smaller_child_idx]):
                break
            else:
                self.swap(index, smaller_child_idx)
            index = smaller_child_idx

    def add(self, item):
        if(self.size == self.capacity):
            self.ensure_capacity()
        self.array[self.size] = item
        self.size +=1
        self.heapify_up()

    def extract_min(self):
        if(self.size == 0): Exception("Empty Heap")
        item = self.array[0]
        self.array[0] = self.array[self.size-1]
        self.size -= 1
        self.heapify_down()
        return item

    def get_min(self):
        if(self.size == 0): Exception("Empty Heap")
        return self.array[0]

    def show(self):
        for i in range(0, self.size):
            print("Item "+str(i)+": "+str(self.array[i]))


if __name__ == '__main__':
    m_heap = minHeap()
    m_heap.add(4)
    m_heap.add(3)
    m_heap.add(8)
    # m_heap.add(8)
    m_heap.show()

    
