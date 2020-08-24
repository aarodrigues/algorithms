#include <iostream>
#include "arraylist.hpp"


int main()
{
    int array[10] = {432,8,530,90,88,231,11,45,677,199};

    std::cout<<"Hello ArrayList!\n";
    ArrayList alist;
    alist.add(432);
    alist.add(8);
    alist.add(530);
    alist.add(90);
    alist.add(88);

    alist.remove(3);
    alist.clear();

    std::cout << alist.size() << std::endl;
    // for(int i = 0; i < alist.size(); i++) {
    //     std::cout << alist.get(i) << std::endl;
    // }

    return 0;
}