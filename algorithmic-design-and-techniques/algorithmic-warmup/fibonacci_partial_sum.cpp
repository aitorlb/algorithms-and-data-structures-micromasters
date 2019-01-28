#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

/* Last Digit of Partial Sum of Fibonacci Numbers from F(m) to F(n)
 *
 * Given the following relationship between sequences exist:
 *
 * 0 1 1 2 3 5 8 13 21 34       // fibs
 *       1 2 4 7 12 20 33       // sums
 *
 * For the sum, we need to compute the last digit of F(i+2) and substract 1
 *
 * For the partial sum, we need to caculate the difference:
 *  sum of F(n) - sum F(m-1) */
int get_fibonacci_partial_sum_fast(long long from, long long to) {
    std::vector<int> p{0, 1, 1 % 10};  // Pisano period

    for (int i = 2; true; ++i) {
        int current = (p[i] + p[i - 1]) % 10;
        if (p[i] == 0 && current == 1) {
            p.pop_back();
            break;
        }
        p.push_back(current);
    }

    int rhs = p[(from + 1) % p.size()];  // F(from+1) mod 10
    rhs = (rhs + 9) % 10;                // Handle decrementing zero
    int lhs = p[(to + 2) % p.size()];    // F(to+2) mod 10
    return ((lhs + 9) - rhs) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    return 0;
}

