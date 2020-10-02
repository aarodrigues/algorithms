
class HashTable:

    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.next = None

    def __init__(self):
        self.array = 10*[None]
        self.array_size = 10
        self.itens_number = 0

    def get_index(self, key):
        str_hash = hash(key)
        return str_hash % self.array_size

    def add(self, key, value):
        index = self.get_index(key)

        if(self.array[index] == None):
            self.array[index] = self.Node(key, value)
        else:
            current = self.array[index]
            while(current.next is not None):
                current = current.next
            current.next = self.Node(key, value)
        self.itens_number += 1

    def get(self, key):
        index = self.get_index()
        if(self.array[index] is not None):
            if(self.array[index].key == key):
                return self.array[index]
            else:
                current = self.array[index]
                while(current.next is not None):
                    if(current.next.key == key):
                        return current.next
                    current = current.next

    def delete(self, key):
        index = self.get_index(key)
        if(self.array[index] is not None):
            if(self.array[index].key == key):
                self.array[index] = self.array[index].next
                self.itens_number -= 1
            else:
                current = self.array[index]
                while(current.next is not None):
                    if(current.next.key == key):
                        current.next = current.next.next
                        self.itens_number -= 1
                    current = current.next


    def show_itens(self):

        for i in range(0, self.array_size):
            if(self.array[i] is not None):
                current = self.array[i]
                print(str(current.key) +" -> "+ str(self.array[i].value))
                while(current.next is not None):
                    print(str(current.next.key) +" -> "+ str(self.array[i].next.value))
                    current = current.next
    

                
if __name__ == '__main__':
    hash_table = HashTable()
    hash_table.add("cucu","hauhauah")
    hash_table.add("biabai","malam")
    hash_table.add("lala","opseic")

    hash_table.delete("cucu")

    hash_table.show_itens()