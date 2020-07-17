#include <iostream>
#include "memoization.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello World" << std::endl;
    Memoization fib;
    // std::cout << fib.Fibonacci(45) << std::endl;
    // std::cout << fib.FibonacciTraditional(45) << std::endl;
    std::cout << fib.Factorial(20) << std::endl;
    // std::cout << fib.FactorialTraditional(20) << std::endl;
    return 1;
}