#include "memoization.hpp"

Memoization::Memoization() {

}

Memoization::~Memoization() {
    
}

long Memoization::Fibonacci(const int &num) {
    if(num <= 0)
        return 0;
    if(num == 1) {
        return 1;
    }else if(this->memo[num] == 0){
        this->memo[num] = this->Fibonacci(num -1) + this->Fibonacci(num -2);
    }
    return this->memo[num];
}

long Memoization::FibonacciTraditional(const int &num){
    if(num <= 0)
        return 0;
    if(num == 1) {
        return 1;
    } else {
        return  this->FibonacciTraditional(num-1) + this->FibonacciTraditional(num-2);
    }    
}

 long Memoization::Factorial(const int &num) {
     if(num == 0 || num == 1) {
         return 1;
     }else if(num > 1) {
         if(this->memo[num] == 0){
            this->memo[num] = num * Factorial(num - 1);
         }
     }
     return this->memo[num];
 }

 long Memoization::FactorialTraditional(const int &num) {
     if(num == 0 || num == 1) {
         return 1;
     }else if(num > 1) {
         return num * Factorial(num - 1);
     }
 }
