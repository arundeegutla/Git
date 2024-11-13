#include <bits/stdc++.h>
using namespace std;

int memo[1 << 21][25];
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    int sum = 0;
    vector<int> unique;
    unordered_map<int, int> freq;
    for (auto x : arr) {
        if (freq[x] == 0) unique.push_back(x);
        freq[x]++;
    }

    for (auto [k, v] : freq) {
        sum += (k * (v - 1));
    }

    function<int(int, int)> go = [&](int used, int last) -> int {
        if (bitset<25>(used).count() == unique.size()) return 0;
        auto& ans = memo[used][last + 1];
        if (ans != -1) return ans;
        int maxx = 0;
        for (int i = 0; i < unique.size(); i++) {
            // didnt use it yet.
            if (((1 << i) & (used)) == 0) {
                maxx = max(maxx, go(used | (1 << i), i) + (last == -1 ? 0 : gcd(unique[last], unique[i])));
            }
        }

        return ans = maxx;
    };

    // cout << go(0, -1) << "\n";
    cout << sum + go(0, -1) << "\n";
}