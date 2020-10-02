class Stack:
    class Node:
        def __init__(self, item):
            self.item = item
            self.next = None

    def __init__(self):
        self.head = None
        self.size = 0

    def put(self,item):
        if(self.head is None):
            self.head = self.Node(item)
        else:
            node = self.Node(item)
            node.next = self.head
            self.head = node
        self.size += 1

    def pop(self):
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
    stack = Stack()
    stack.put(2)
    stack.put(4)
    stack.put(6)
    stack.put(8)
    stack.put(10)

    print(stack.pop())
    print(stack.pop())
    print("##############")

    stack.show()
        