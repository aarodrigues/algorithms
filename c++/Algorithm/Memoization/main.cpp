#include <iostream>
#include "memoization.hpp"


int main()
{
    std::cout<<"Hello Memoization!\n";
    Memoization memo;
    std::cout << memo.factorial(6) << std::endl;
    std::cout << memo.fibonacci(3) << std::endl;

    return 0;
}