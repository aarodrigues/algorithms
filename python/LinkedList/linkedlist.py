
class LinkedList:

    class Node:

        def __init__(self, item):
            self.next = None
            self.item = item

    def __init__(self):
        self.root = None
        self.size = 0

    def append(self, item):
        if(self.root == None):
            self.root = self.Node(item)
        else:
            current = self.root
            while(current.next != None):
                current = current.next
            current.next = self.Node(item)
        self.size +=1

    def preappend(self, item):
        node = self.Node(item)
        node.next = self.root
        self.root = node
        self.size +=1

    def print(self):
        current = self.root
        str_list = ""
        while(current.next != None):
            str_list += " " +str(current.item)
            current = current.next
        str_list += " "+ str(current.item)
        print(str_list)

    def remove(self, item):
        if(self.root.item == item):
            removed = self.root.item
            self.root = self.root.next
            self.size -= 1
            return removed
        current = self.root
        while(current.next != None):
            if(current.next.item == item):
                removed = current.next.item
                current.next = current.next.next
                self.size -= 1
                return removed
            current = current.next
        return None

    def contains(self, item):
        current = self.root
        while(current.next != None):
            if(current.item == item):
                return True
            current = current.next
        return False


def main():
    list = LinkedList()
    list.append(3)
    list.append(5)
    list.append(7)
    list.preappend(9)
    print("size: "+str(list.size))
    list.print()
    print("removed: "+str(list.remove(3)))
    print("size: "+str(list.size))
    list.print()

if __name__ == "__main__":
    main()