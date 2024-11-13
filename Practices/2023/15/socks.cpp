#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    int tot = 0;
    vector<int> stripped;
    unordered_map<int, int> freq;
    for (auto& x : arr) {
        freq[x]++;
        if (freq[x] > 2) {
                }
    }

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (arr[i] > 0 && j < n) {
            int match = min(arr[i], arr[j]);
            arr[i] -= match;
            arr[j] -= match;
            tot += match;
            j++;
        }
    }

    cout << tot << "\n";
}