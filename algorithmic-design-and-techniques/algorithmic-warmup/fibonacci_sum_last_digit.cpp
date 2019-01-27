#include <iostream>
#include <vector>
#include <cassert>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/* Compute huge fibonacci F(n) modulo 10 using Pisano period P(m)

   Given the following relationship between sequences exist:

   0 1 1 2 3 5 8 13 21 34   // fibs
         1 2 4 7 12 20 33      // sums

   We need to compute the last digit of F(n+2) and substract 1 */
int fibonacci_sum_fast(long long n) {
    std::vector<int> p {0, 1, 1 % 10}; // Pisano period

    for (int i = 2; true; ++i){
        int current = (p[i] + p[i-1]) % 10;
        if ( p[i] == 0 && current == 1) {
            p.pop_back();
            break;
        }
        p.push_back(current);
    }

    int fib = p[(n + 2) % p.size()]; // F(n+2) % 10
    if (fib == 0) return 9;
    return --fib;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}

