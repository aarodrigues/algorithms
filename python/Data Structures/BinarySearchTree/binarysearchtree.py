class BinarySearchTree:
    class Node:
        def __init__(self, item):
            self.right = None
            self.left = None
            self.item = item
        
        def min(self):
            if(self.left is None):
                return self
            else:
                return self.left.min()


    def __init__(self):
        self.root = None
        self.size = 0

    def insert(self, item):
        self.root = self.insert_item(item, self.root)

    def insert_item(self, item, node):
        if(node is None):
            node = self.Node(item)
        else:
            if(item < node.item):
                node.left = self.insert_item(item, node.left)
            elif(item > node.item):
                node.right = self.insert_item( item, node.right)
        self.size += 1
        return node

    def delete(self, item):
        self.root = self.delete_item(item, self.root)

    def delete_item(self, item, node):
        if(node is not None):
            if(item < node.item):
                node.left = self.delete_item(item, node.left)
            elif(item > node.item):
                node.right = self.delete_item(item, node.right)
            else:
                if(node.left is None and node.right is None):
                    node = None
                elif(node.left is None):
                    node = node.right
                elif(node.right is None):
                    node = node.left
                else:
                    min_right = node.right.min()
                    node.item = min_right.item
                    node.right = self.delete_item(node.item, node.right)
        
                self.size -= 1
        return node

    def printInOrder(self, node = None):
        if(node is None):
            node = self.root
        if(node.left is not None):
           self.printInOrder(node.left)
        print(node.item)
        if(node.right is not None):
           self.printInOrder(node.right)



# if __name__ == '__main__':
#     b_tree = BinarySearchTree()
#     b_tree.insert(5)
#     b_tree.insert(2)
#     b_tree.insert(4)
#     b_tree.insert(6)
#     b_tree.printInOrder()
#     print("#####################")
#     b_tree.delete(5)
#     b_tree.printInOrder()
        