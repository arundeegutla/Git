#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> start(n);
    vector<int> end(m);

    for (auto& x : start) cin >> x;
    for (auto& x : end) cin >> x;

    unordered_map<int, int> dist;
    for (auto x : start) {
        for (auto y : end) {
            if (y - x >= 0) {
                dist[y - x]++;
            }
        }
    }

    vector<pair<int, int>> arr;
    for (auto [k, v] : dist) {
        arr.push_back({-v, k});
    }
    sort(arr.begin(), arr.end());

    cout << (arr.size() ? arr[0].second : 0LL) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}
