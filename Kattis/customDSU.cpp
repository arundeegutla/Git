#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> size, parent, sum;
    vector<vector<int>> adj;
    DSU(int n) {
        n++;
        size.resize(n, 1);
        parent.resize(n);
        sum.resize(n);
        adj.resize(n);
        for (int i = 0; i < n; i++)
            sum[i] = parent[i] = i;
    }
    int find(int node) {
        return node == parent[node] ? node : find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        size[b] = 0;
        adj[a].push_back(b);
        return true;
    }
    bool push(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;

        if (pa == a) {
            size[pa] = 1;
            sum[pa] = a;

            for (auto& x : adj[a]) {
                parent[x] = x;
            }

            if (adj[a].size()) {
                int first = adj[a][0];
                for (auto& x : adj[a]) {
                    join(x, first);
                }
            }

            adj[a].clear();
            adj[pb].push_back(a);
            size[pb] += 1;
            sum[pb] += a;
            parent[a] = pb;

        } else {
            size[pa] -= 1;
            sum[pa] -= a;
            adj[pb].push_back(a);
            size[pb] += 1;
            sum[pb] += a;

            // connecting pa to xxx.
            for (auto& x : adj[a]) {
                parent[x] = pa;
                adj[pa].push_back(x);
            }
            adj[a].clear();
            adj[pb].push_back(a);
            parent[a] = pb;
        }

        return true;
    }
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        DSU dsu(n);
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int a, b;
                cin >> a >> b;
                dsu.join(a, b);
                for (auto x : dsu.parent) {
                    cout << x << ":" << dsu.find(x) << " ";
                }
                cout << "\n";
            } else if (type == 2) {
                int a, b;
                cin >> a >> b;
                dsu.push(a, b);

                for (auto x : dsu.parent) {
                    cout << x << ":" << dsu.find(x) << " ";
                }
                cout << "\n";

            } else {
                int x;
                cin >> x;
                int p = dsu.find(x);
                cout << dsu.size[p] << " " << dsu.sum[p] << "\n";
            }
        }
    }
}