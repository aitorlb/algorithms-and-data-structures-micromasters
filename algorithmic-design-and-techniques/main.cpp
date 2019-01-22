/* Maximum Pairwise Product Problem
Find the maximum product of two distinct numbers
in a sequence of non-negative integers.
Input: A sequence of non-negative
integers.
Output: The maximum value that
can be obtained by multiplying
two different elements from the sequence */

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProductNaive(const vector<int> &numbers)
{
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long) (numbers[i])) * numbers[j] > result) {
                result = ((long long) (numbers[i])) * numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& v)
{
    int first = 0;
    int second = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] > first) {
            second = first;
            first = v[i];
        } else if (v[i] > second) {
            second = v[i];
        }
    }
    return first * static_cast<long long>(second);
}

int main()
{
    /* Stress Test
    while (true) {
        int n = rand() % 1000 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        long long res1 = MaxPairwiseProductNaive(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << ', ' << res2 << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    } */

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result {MaxPairwiseProductFast(numbers)};
    cout << result << "\n";
    return 0;
}
