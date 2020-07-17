
class Memoization {
  public:
    Memoization();
    ~Memoization();
    long Fibonacci(const int &num);
    long FibonacciTraditional(const int &num);
    long Factorial(const int &num);
    long FactorialTraditional(const int &num);

  private:
    long memo[10000];
};