#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        vector<int> arr(12);
        for (auto& x : arr) cin >> x;
        bool allZeroes = false;
        for (auto x : arr) allZeroes &= x == 0;
        if (allZeroes) break;
        sort(arr.begin(), arr.end());

        int count = 0;
        do {
            auto sum1 = arr[0] + arr[3] + arr[6] + arr[10];
            auto sum2 = arr[1] + arr[2] + arr[3] + arr[4];
            auto sum3 = arr[4] + arr[6] + arr[9] + arr[11];
            auto sum4 = arr[0] + arr[2] + arr[5] + arr[7];
            auto sum5 = arr[1] + arr[5] + arr[8] + arr[11];
            auto sum6 = arr[7] + arr[8] + arr[9] + arr[6];

            count += sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 && sum5 == sum6;
        } while (next_permutation(arr.begin(), arr.end()));

        cout << count << "\n";
    }

    return 0;
}