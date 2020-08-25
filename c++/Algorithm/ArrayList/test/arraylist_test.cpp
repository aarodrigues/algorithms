#include <gtest/gtest.h>
#include "../arraylist.hpp"

class ArrayListTest : public ::testing::Test {
    protected:
        void SetUp() override {
            for(int i = 0; i < 5; i++ ) {
                alist.add(i*2);
            }
        }

        void TearDown() override {

        }
        ArrayList<int> alist;
};

TEST_F(ArrayListTest, AmountOfElements) {
    EXPECT_EQ(alist.size(), 5);
}

TEST_F(ArrayListTest, getElementByIndex) {
    alist.add(7);
    EXPECT_EQ(alist.get(5), 7);
}

TEST_F(ArrayListTest, sizeAfterRemoveOneElement) {
    int size = alist.size();
    alist.remove(0);
    EXPECT_EQ(alist.size(), size-1);
}

TEST_F(ArrayListTest, clearAllElements) {
    alist.clear();
    EXPECT_EQ(alist.size(), 0);
}

int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);
       return RUN_ALL_TESTS();

}
