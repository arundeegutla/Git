#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (auto& arr : graph) {
        for (auto& x : arr) {
            cin >> x;
        }
    }

    vector<vector<ll>> memo(n, vector<ll>(1 << n, -1));
    int MOD = 1e9 + 7;
    auto go = [&](int at, int used, auto&& go) -> ll {
        if (at == n) return 1;

        auto& ans = memo[at][used];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        ll ways = 0;
        for (int i = 0; i < n; i++) {
            if ((used & (1 << i)) != 0) continue;
            if (graph[at][i] == 0) continue;
            ways += go(at + 1, used | (1 << i), go);
            ways %= MOD;
        }

        return ans = ways;
    };

    cout << go(0, 0, go) << "\n";
}
