#include <iostream>

/* Problem Introduction
   In this problem, you will design and implement an elementary greedy algorithm
   used by cashiers all over the world millions of times per day.

   Problem Description
   Task. The goal in this problem is to find the minimum number of coins needed
   to change the input value (an integer) into coins with denominations 1, 5,
   and 10. Input Format. The input consists of a single integer m. Constraints.
   1 ≤ m ≤ 10 3 . Output Format. Output the minimum number of coins with
   denominations 1, 5, 10 that changes m.*/

int changing_money(int dollars) {
    int coins[]{10, 5, 1};  // Sort coins descendingly
    int change = 0;

    for (int coin : coins) {       // iterate over coins
        while (dollars >= coin) {  //  while dollars left can be changed by coin
            change += dollars / coin;  // count how many of coin can be changed
            dollars %= coin;           // update dollars left
        }
    }

    return change;  // return total number of coins
}

int main() {
    int money;
    std::cin >> money;
    std::cout << changing_money(money);
    return 0;
}
