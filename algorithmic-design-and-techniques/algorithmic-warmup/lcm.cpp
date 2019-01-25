#include <iostream>
#include <cassert>

/* 4 Least Common Multiple

Problem Introduction
The least common multiple of two positive integers a and b is the least positive
integer m that is divisible by both a and b.

Problem Description
Task. Given two integers a and b, find their least common multiple.
Input Format. The two integers a and b are given in the same line separated by space.
Constraints. 1 ≤ a, b ≤ 2 · 10 9 .
Output Format. Output the least common multiple of a and b. */

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd_fast(b, a % b);
}

long long lcm_fast(int a, int b) {
  if (a == 0 && b == 0) {
    return 0;
  }
  return (static_cast<long long>(a) * b) / gcd_fast(a, b);
}

void test_solution() {
  assert(lcm_naive(6, 8) == 24);
  assert(lcm_fast(6, 8) == 24);
  std::cout << "OK\n";
}

int main() {
  //test_solution();
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

