#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
signed main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> projects(n);
    for (auto& x : projects) {
        int a, b, p;
        cin >> a >> b >> p;
        x = {a, {b, p}};
    }
    sort(projects.begin(), projects.end());

    vector<ll> memo(n, -1);
    function<ll(int)> go = [&](int at) -> ll {
        if (at == n) return 0;
        int start = projects[at].first;
        int end = projects[at].second.first;
        int w = projects[at].second.second;

        auto& ans = memo[at];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        // take.
        int lo = at + 1;
        int hi = n - 1;
        int best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (projects[mid].first > end) {
                hi = (best = mid) - 1;
            } else {
                lo = mid + 1;
            }
        }
        ll take = w;
        if (best != -1) {
            take += go(best);
        }

        ll leave = go(at + 1);

        return ans = max(take, leave);
    };

    cout << go(0) << "\n";
}