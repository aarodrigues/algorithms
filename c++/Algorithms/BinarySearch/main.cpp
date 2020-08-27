#include <iostream>
#include "binarysearch.hpp"


int main()
{
    std::cout<<"Hello Binary Search!\n";
    BinarySearch bs;
    std::vector<int> ordered_list = {2, 3 ,5 , 7, 23, 37, 40, 41, 55, 58, 63};
    bool t = bs.search(ordered_list,63);
    std::cout << "Found out: " << t << std::endl;

    return 0;
}