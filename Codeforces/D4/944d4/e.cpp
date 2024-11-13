#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> points(k);
    for (auto& x : points) cin >> x;
    vector<int> time(k);
    for (auto& x : time) cin >> x;

    vector<pair<int, int>> info;
    info.push_back({0, 0});
    for (int i = 0; i < k; i++)
        info.push_back({points[i], time[i]});
    info.push_back(info.back());

    while (q--) {
        int d;
        cin >> d;

        int lo = 0;
        int hi = k + 1;
        int best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (info[mid].first <= d) {
                lo = (best = mid) + 1;
            } else {
                hi = mid - 1;
            }
        }
        assert(best != -1);

        auto prev = info[best];
        if (prev == info.back()) {
            cout << prev.second << " ";
            continue;
        }
        auto next = info[best + 1];

        ll totTime = info[best].second;
        auto totDistance = next.first - prev.first;
        auto timeTook = next.second - prev.second;
        auto newDist = d - prev.first;
        totTime += ((newDist * timeTook) / totDistance);
        cout << totTime << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}