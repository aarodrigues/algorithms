#include <iostream>

class Memoization {
    public:
        long fibonacci(const int &num) {
            int memo[1000];
            if(num <= 0)
                return 0;
            if(num == 1)
                return 1;
            else if(memo[num] == 0) {
                memo[num] = fibonacci(num - 1) + fibonacci(num - 2);
            }
            return memo[num];
        }

        long factorial(const int &num) {
            int memo[1000];
            if(num == 0 || num == 1) {
                return 1;
            }else if(num > 1) {
                if(memo[num] == 0){
                    memo[num] = num * factorial(num - 1);
                }
            }
            return memo[num];
        }
};