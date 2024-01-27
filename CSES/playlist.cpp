#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    set<int> hset;
    int maxx = 0;
    for (int l = 0, r = 0; r < n; r++) {
        while (hset.count(arr[r])) {
            hset.erase(arr[l++]);
        }
        hset.insert(arr[r]);
        maxx = max(maxx, r - l + 1);
    }

    cout << maxx << "\n";
}