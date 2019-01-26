#include <iostream>

// Compute the Last Digit of a Large Fibonacci Number

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1) return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(long long n) {
    if (n <= 1) return n;

    int c = 0;  // F(0)
    int b = 1;  // F(1)
    int a = 1;  // F(2)

    for (int i = 3; i <= n; ++i) {
        c = b;             // F(i-2) = F(i-1)
        b = a;             // F(i-1) = F(i)
        a = (b + c) % 10;  // F(i) = (F(-1) + F(-2)) mod 10
    }

    return a;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
    return 0;
}

