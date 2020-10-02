
class ArrayList:
    def __init__(self):
        self.num_elements = 0
        self.default_array_size = 2
        self.array_size = default_array_size
        self.array = [None] * default_array_size

    def add(self, item):
        self.resize()
        self.array[self.num_elements] = item
        self.num_elements += 1

    def get(self, idx):
        if(idx <= self.num_elements):
            return self.array[idx]

    def remove(self, idx):
        if(idx <= self.num_elements):
            for i in range(idx,self.num_elements):
                self.array[i] = self.array[i+1]
            self.num_elements -= 1

    def size(self):
        return self.num_elements

    def resize(self):
        if(self.num_elements < self.array_size):
            return
        else:
            self.array_size *= 2
            temp = [None] * self.array_size
            for i in range(0,self.num_elements):
                temp[i] = self.array[i]
            self.array = temp

            
