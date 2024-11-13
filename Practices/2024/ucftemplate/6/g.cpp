#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    using info = pair<int, int>;
    vector<info> bottles(n);
    vector<info> bases(m);
    for (auto& [x, y] : bottles) cin >> x >> y;
    for (auto& [x, y] : bases) cin >> x >> y;
    ll ox, oy;
    cin >> ox >> oy;

    priority_queue<pair<int, info>> pq;

    for (int i = 0; i < n; i++) {
        auto [bx, by] = bottles[i];
        int actual = 2 * (abs(ox - bx) + abs(oy - by));
        for (int j = 0; j < m; j++) {
            auto [bax, bay] = bases[j];
            int here = (actual / 2) + abs(bax - bx) + abs(bay - by);
            pq.push({actual - here, {i, j}});
        }
    }

    vector<bool> doneBottle(n);
    vector<bool> doneBases(m);

    bool hasOne = false;
    ll cost = 0;
    while (pq.size()) {
        auto [_, x] = pq.top();
        pq.pop();
        auto [b, base] = x;
        if (doneBases[base] || doneBottle[b]) continue;
        if (_ < 0 && hasOne) break;
        hasOne = true;
        auto [bx, by] = bottles[b];
        auto [bax, bay] = bases[base];
        cost += abs(ox - bx) + abs(oy - by) + abs(bax - bx) + abs(bay - by);
        doneBases[base] = true;
        doneBottle[b] = true;
    }

    assert(hasOne);
    for (int i = 0; i < n; i++) {
        auto [bx, by] = bottles[i];
        if (!doneBottle[i]) {
            cost += abs(ox - bx) + abs(oy - by) + abs(ox - bx) + abs(oy - by);
        }
    }
    cout << cost << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}