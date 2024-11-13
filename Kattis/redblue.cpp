#include <bits/stdc++.h>
using namespace std;

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

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    int numBlues = 0;
    int numReds = 0;

    using Info = pair<int, pair<int, int>>;
    vector<Info> edges;

    while (m--) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (c == 'B') {
            edges.push_back({1, {a, b}});
            edges.push_back({1, {b, a}});
            numBlues++;
        } else {
            edges.push_back({0, {a, b}});
            edges.push_back({0, {b, a}});
            numReds++;
        }
    }

    if (numBlues < k || numReds < (n - 1 - k)) {
        cout << 0 << "\n";
        return 0;
    }

    DSU dsu(n);
    sort(edges.begin(), edges.end());
    int minBlues = 0;
    for (auto e : edges)
        if (dsu.join(e.second.first, e.second.second)) {
            minBlues += e.first;
        }

    if (minBlues > k) {
        cout << 0 << "\n";
        return 0;
    }
    DSU dsu2(n);
    sort(edges.begin(), edges.end(), [&](Info& a, Info& b) -> bool {
        return a.first > b.first;
    });
    int minReds = 0;
    for (auto e : edges)
        if (dsu2.join(e.second.first, e.second.second)) {
            minReds += !e.first;
        }
    if (minReds > (n - 1 - k)) {
        cout << 0 << "\n";
        return 0;
    }
    cout << 1 << "\n";
}
