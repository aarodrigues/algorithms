#include <gtest/gtest.h>
#include <iostream>
#include "linked_list.hpp"

class LinkedListTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // std::cout << "Triggered on the start of the test" << std::endl;
  }

  void TearDown() override {
    // std::cout << "Triggered on the end of the test" << std::endl;
  }

  LinkedList list;
};

TEST_F(LinkedListTest, Size) {
    list.append(2);
    list.append(4);
    list.append(6);
  EXPECT_EQ(list.size(), 3);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
       return RUN_ALL_TESTS();
}