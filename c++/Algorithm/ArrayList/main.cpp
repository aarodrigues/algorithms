#include <iostream>
#include "arraylist.hpp"


int main()
{
    std::cout<<"Hello ArrayList!\n";
    ArrayList<double> alist;
    alist.add(10.5);
    alist.add(8.2);
    alist.add(1.5);

    // alist.add(432);
    // alist.add(8);
    // alist.add(530);
    // alist.add(90);
    // alist.add(88);

    // alist.remove(3);
    // alist.clear();

    std::cout << alist.size() << std::endl;
    for(int i = 0; i < alist.size(); i++) {
        std::cout << alist.get(i) << std::endl;
    }

    return 0;
}