#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> memo(m, vector<ll>(1 << (n + 1), -1));
    int MOD = 1e9 + 7;
    auto go = [&](int at, int prevMask, auto&& go) -> ll {
        if (at == m) return 1;

        auto& ans = memo[at][prevMask];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        vector<int> available;
        for (int i = 0; i < n; i++) {
            if (((prevMask) & (1 << i)) != 0) continue;
            if (((prevMask << 1) & (1 << i)) != 0) continue;
            if (((prevMask >> 1) & (1 << i)) != 0) continue;
            available.push_back(i);
        }

        ll ways = 0;
        for (int mask = 0; mask < (1 << available.size()); mask++) {
            int here = 0;
            for (int i = 0; i < available.size(); i++)
                if ((mask & (1 << i)) != 0)
                    here |= 1 << available[i];

            bool cant = false;
            for (int i = 0; i < n; i++)
                cant |= (here & (3 << i)) == (3 << i);

            if (cant) continue;
            ways += go(at + 1, here, go);
            ways %= MOD;
        }

        return ans = ways;
    };

    cout << go(0, 0, go) << "\n";
}