#include <iostream>
#include <cassert>

// Problem Description
// Task. Given two integers a and b, find their greatest common divisor.
// Input Format. The two integers a, b are given in the same line separated by space.
// Constraints. 1 ≤ a, b ≤ 2 · 10^9 .
// Output Format. Output GCD(a, b).

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd_fast(b, a%b);
}

void test_solution() {
  assert(gcd_naive(18, 35) == 1);
  assert(gcd_fast(18, 35) == 1);
  for (int n = 0; n < 20; ++n) {
    assert(gcd_naive(n, n+1) == gcd_fast(n, n+1));
  }
}

int main() {
  //test_solution();
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}

