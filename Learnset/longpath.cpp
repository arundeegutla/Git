#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    using info = pair<int, int>;
    priority_queue<info, vector<info>, greater<info>> q;
    vector<int> mindist(n, 1e18);
    mindist[0] = 0;
    q.push({0, 0});
    while (q.size()) {
        auto [dHere, here] = q.top();
        q.pop();
        if (dHere < mindist[here]) continue;
        for (auto [e, w] : graph[here]) {
            if (mindist[e] > dHere + w) {
                mindist[e] = dHere + w;
                q.push({dHere + w, e});
            }
        }
    }

    priority_queue<info> q2;
    q2.push({0, 0});
    vector<int> maxdist(n, -1e18);
    maxdist[0] = 0;

    while (q2.size()) {
        auto [dHere, here] = q2.top();
        q2.pop();
        if (dHere > maxdist[here]) continue;
        for (auto [e, w] : graph[here]) {
            if (maxdist[e] < dHere + w) {
                maxdist[e] = dHere + w;
                q2.push({dHere + w, e});
            }
        }
    }

    cout << mindist[n - 1] << " " << maxdist[n - 1] << "\n";
}

signed main() {
    int c;
    cin >> c;

    while (c--) {
        solve();
    }
}