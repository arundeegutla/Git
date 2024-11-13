#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    map<int, int> hmap;
    for (int i = 0; i < n; i++) {
        int other = target - arr[i];
        if (hmap.find(other) != hmap.end()) {
            cout << hmap[other] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        hmap[arr[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}