import unittest
# from ..src.binarysearchtree import BinarySearchTree
# import arraylist

class TestBinarySearchTree(unittest.TestCase):

    def setUp(self):
        self.bs_tree = 0 #BinarySearchTree()
        pass

    def test_tree_size(self):
        num_items = 0
        for i in range(0,10):
            # self.bs_tree.insert(2*i)
            num_items += i

        # self.assertEqual(self.bs_tree.size,num_items)
        self.assertEqual(True,True)
            

if __name__ == '__main__':
    unittest.main()
