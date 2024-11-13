#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    unordered_map<char, int> freq;
    string s;
    cin >> s;
    for (auto c : s) {
        freq[c]++;
    }

    int MOD = 11092019;
    int tot = 1;
    for (auto [k, v] : freq) {
        int have = v + 1;
        tot *= have;
        tot %= MOD;
    }

    cout << tot << "\n";
}