class Queue:
    class Node:
        def __init__(self, item):
            self.item = item
            self.next = None


    def __init__(self):
        self.head = None
        self.size = 0

    def add(self, item):
        if(self.head is None):
            self.head = self.Node(item)
        else:
            current = self.head
            while(current.next is not None):
                current = current.next
            current.next = self.Node(item)
        self.size += 1

    def get(self):
        if(self.head is not None):
            item = self.head.item
            self.head = self.head.next
            self.size -= 1
        return item

    def show(self):
        current = self.head
        print(current.item)
        while(current.next is not None):
            print(current.next.item)
            current = current.next

if __name__ == '__main__':
    queue = Queue()
    queue.add(2)
    queue.add(4)
    queue.add(6)
    queue.add(8)
    queue.add(10)
    queue.show()
    print(queue.get())
    print("##################")
    queue.show()