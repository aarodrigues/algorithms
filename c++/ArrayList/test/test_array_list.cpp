#include <gtest/gtest.h>
#include <iostream>
#include "array_list.hpp"

class ArrayListTest : public ::testing::Test {
 protected:
  void SetUp() override {
    for (int i = 0; i < 16; i++){
       list.add(i*5);
    }
    // std::cout << "Triggered on the start of the test" << std::endl;
  }

  void TearDown() override {
    list.clear();
    // std::cout << "Triggered on the end of the test" << std::endl;
  }

  ArrayList list;
};

TEST_F(ArrayListTest, Size) {
  EXPECT_EQ(list.size(), 16);
}

TEST_F(ArrayListTest, RemoveByIndex) {
  EXPECT_EQ(list.remove(2), true);
}

TEST_F(ArrayListTest, Contains) {
  EXPECT_EQ(list.contains(15), true);
}

TEST_F(ArrayListTest, RemoveByValue) {
  list.remove_by_val(15);
  EXPECT_EQ(list.contains(15), false);
}

TEST_F(ArrayListTest, Clear) {
  list.clear();
  EXPECT_EQ(list.size(), 0);
}

TEST_F(ArrayListTest, Get) {
  EXPECT_EQ(list.get(5), 25);
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
       return RUN_ALL_TESTS();
}