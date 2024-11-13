#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    unordered_map<int, int> freq;

    ll ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        freq[arr[r]]++;
        while (freq.size() > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0)
                freq.erase(arr[l]);
            l++;
        }
        ans += r - l + 1;
    }

    cout << ans << "\n";
}