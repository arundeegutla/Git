#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

struct DSU {
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node) {
        return node == parent[node] ? node : parent[node] = find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

void solve() {
    int s, p;
    cin >> s >> p;

    vector<pair<int, int>> ps(p);
    for (auto& [x, y] : ps) {
        cin >> x >> y;
    }

    if (p <= s) {
        cout << 0 << "\n";
        return;
    }

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            auto [x1, y1] = ps[i];
            auto [x2, y2] = ps[j];
            int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            edges.push_back({dist, {i, j}});
            edges.push_back({dist, {j, i}});
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(p);
    int maxx = 0;
    int numEdges = 0;
    for (auto e : edges) {
        if (numEdges + s >= p) break;
        if (dsu.join(e.second.first, e.second.second)) {
            numEdges++;
            maxx = e.first;
        }
    }

    cout << fixed << setprecision(2) << sqrt(maxx) << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}