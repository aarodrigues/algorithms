class ArrayList:
    def __init__(self):
        self.array_size = 10
        self.list = [None] * self.array_size
        self.num_item = 0

    def insert(self, idx, item):
        if(self.num_item + 1 == self.array_size):
            self.resize()
        if(self.list[idx] != None):
            self.num_item -= 1
        self.list[idx] = item
        self.num_item += 1

    def append(self, item):
        if(self.num_item + 1 == self.array_size):
            self.resize()
        self.list[self.num_item] = item
        self.num_item += 1

    def delete(self,index):
        for idx in range(index,self.num_item-1):
            self.list[idx] = self.list[idx +1]
        self.list[self.num_item -1] = None
        self.num_item -= 1
        print("deleted")

    def contains(self,item):
        exist = False
        for x in self.list:
            if(x == item):
                exist = True
                break
        return exist

    def size(self):
        return self.num_item

    def resize(self):
        new_size = self.array_size*2
        new_array = [None] * new_size
        for idx in range(0,self.num_item):
            new_array[idx] = self.list[idx]
        self.list = new_array

    def print_list(self):
        str_list = ""
        for idx in range(0,self.num_item):
            str_list += " "+str(self.list[idx])
        print(str_list)



def main():
    list = ArrayList()
    for idx in range(0,15):
        list.append(idx*2)

    list.print_list()
    print(list.contains(12))
    print(list.size())
    # list.delete(1)
    # list.print_list()
    # list.insert(1,2)
    # list.print_list()

if __name__ == "__main__":
    main()