#include <cassert>
#include <iostream>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is
// slow.
//    You may also want to submit it to the grader to ensure that it gets the
//    "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the
// lines reading the input,//    uncomment the line with a call to
// test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the
//    naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it,
// and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to
// fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1) return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Computes up to F(92) = 7'540'113'804'746'346'429, then overflows
long long fibonacci_fast(int n) {
    if (n <= 1) return n;

    long long c = 0;  // F(0)
    long long b = 1;  // F(1)
    long long a = 1;  // F(2)

    for (int i = 3; i <= n; ++i) {
        c = b;      // F(i-2) = F(i-1)
        b = a;      // F(i-1) = F(i)
        a = b + c;  // F(i) = F(-1) + F(-2)
    }

    return a;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}

