#include <iostream>
#include <vector>

/* Problem Introduction
   A thief finds much more loot than his bag can fit. Help him to find the most
   valuable combination of items assuming that any fraction of a loot item can
   be put into his bag.

   Problem Description
   Task. The goal of this code problem is to implement an algorithm for the
   fractional knapsack problem. Input Format. The first line of the input
   contains the number n of items and the capacity W of a knapsack. The next n
   lines define the values and weights of the items. The i-th line contains
   integers v i and w i —the value and the weight of i-th item, respectively.
   Constraints. 1 ≤ n ≤ 10 3 , 0 ≤ W ≤ 2 · 10 6 ; 0 ≤ v i ≤ 2 · 10 6 , 0 < w i ≤
   2 · 10 6 for all 1 ≤ i ≤ n. All the numbers are integers. Output Format.
   Output the maximal value of fractions of items that fit into the knapsack.
   The absolute value of the difference between the answer of your program and
   the optimal value should be at most 10 −3 . To ensure this, output your
   answer with at least four digits after the decimal point (otherwise your
   answer, while being computed correctly, can turn out to be wrong because of
   rounding issues).*/

using namespace std;

vector<double> value_to_weight_ratio(int const size, vector<int> const& v, vector<int> const& w) {
    std::vector<double> v2w;
    
    for (int i = 0; i < size; ++i) {
        v2w.push_back(static_cast<double>(v[i]) / w[i]);
    }

    return v2w;
}

int find_most_valuable_item(vector<double> const& v2w) {
    size_t size = v2w.size();
    int index = 0;
    double max = 0.0;

    for (size_t i = 0; i < size; ++i) {
        if (v2w[i] > max) {
            max = v2w[i];
            index = i;
        }
    }
    
    return index;
}

double maximize_loot(int const items, int capacity, vector<int> const& values, vector<int> const& weights) {
    double total_value = 0.0;
    vector<double> v2w = value_to_weight_ratio(items, values, weights);

    while (capacity) {
        int mvi = find_most_valuable_item(v2w);
        double value = values[mvi];
        int weight = weights[mvi];

        if (weight > capacity) {
            weight = capacity;
            value = weight * v2w[mvi];
        }

        total_value += value;
        capacity -= weight;
        v2w[mvi] = 0;
    }

    return total_value;
}

int main() {
    int items, capacity;
    cin >> items >> capacity;
    vector<int> values(items);
    vector<int> weights(items);
    for (int i = 0; i < items; ++i) {
        cin >> values[i] >> weights[i];
    }
    
    cout.precision(10);
    cout << maximize_loot(items, capacity, values, weights);
    return 0;
}
