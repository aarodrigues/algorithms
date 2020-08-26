import unittest
from ..src import arraylist
# import arraylist

class TestArrayList(unittest.TestCase):

    def setUp(self):
        self.array = arraylist.ArrayList()
        pass

    def test_append(self):
        array_test = []
        for i in range(0,10):
            self.array.append(2*i)
            array_test[i] = 2*i

        self.assertEqual(array_test,self.array.list)
            

if __name__ == '__main__':
    unittest.main()
