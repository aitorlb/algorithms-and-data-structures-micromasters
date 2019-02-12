#include <iostream>

/*Problem Introduction
  You have n ads to place on a popular Internet page. For each ad, you know how
  much is the advertiser willing to pay for one click on this ad. You have set up n
  slots on your page and estimated the expected number of clicks per day for each
  slot. Now, your goal is to distribute the ads among the slots to maximize the
  total revenue.

  Problem Description
  Task. Given two sequences a 1 , a 2 , . . . , a n (a i is the profit per click of the i-th ad) and b 1 , b 2 , . . . , b n (b i is
  the average number of clicks per day of the i-th slot), we need to partition them into n pairs (a i , b j )
  such that the sum of their products is maximized.
  Input Format. The first line contains an integer n, the second one contains a sequence of integers
  a 1 , a 2 , . . . , a n , the third one contains a sequence of integers b 1 , b 2 , . . . , b n .
  Constraints. 1 ≤ n ≤ 10 3 ; −10 5 ≤ a i , b i ≤ 10 5 for all 1 ≤ i ≤ n.
  Output Format. Output the maximum value of
  n
  ∑︀ ai ci , where c 1 , c 2 , . . . , c n is a permutation of b 1 , b 2 , . . . , b n .
  i=1
  */

void merge(int arr[], int l, int r, int m) {
    int* temp = new int[r-l+1];
    int i = l;
    int j = m+1;
    int k = 0;

    while (i <= m && j <= r) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for(k = 0, i = l; i <= r; ++i, ++k) {
        arr[i] = temp[k];
    }

    delete []temp;
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, r, m);
    }
}

long long maximize_ad_revenue(int slots, int profit[], int clicks[]) {
    long long total_revenue = 0;
    merge_sort(profit, 0, slots-1);
    merge_sort(clicks, 0, slots-1);

    for (int i = 0; i < slots; ++i) {
        total_revenue += static_cast<long long>(profit[i]) * clicks[i];
    }

    return total_revenue;
}


int main() {
    int slots;
    std::cin >> slots;
    int profit_per_click[slots];
    int clicks_per_slot[slots];
    for (int i = 0; i < slots; ++i) {
        std::cin >> profit_per_click[i];
        std::cin >> clicks_per_slot[i];
    }

    std::cout << maximize_ad_revenue(slots, profit_per_click, clicks_per_slot);
    return 0;
}
