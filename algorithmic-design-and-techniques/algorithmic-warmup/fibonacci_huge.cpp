#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1) return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

/* Compute huge fibonacci F(n) modulo m using Pisano period P(m)
   For any integer m ≥ 2, the sequence F n mod m is periodic.
   The period always starts with 0 1 and is known as Pisano period.
   F(n) mod m = F(n mod P(m)) mod m */
int get_fibonacci_huge_fast(long long n, int m) {
    std::vector<int> p{0, 1, 1 % m};  // Pisano period

    for (int i = 2; m > 2; ++i) {
        int current = (p[i] + p[i - 1]) % m;
        if (p[i] == 0 && current == 1) {
            p.pop_back();
            break;
        }
        p.push_back(current);
    }

    return p[n % p.size()];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}

