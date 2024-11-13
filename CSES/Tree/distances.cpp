#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> seen(n);
    function<pair<int, int>(int)> dfs = [&](int at) -> pair<int, int> {
        if (seen[at]) return {-1, -1};
        seen[at] = true;
        pair<int, int> ans = {0, at};
        for (auto& e : tree[at]) {
            auto here = dfs(e);
            here.first += 1;
            ans = max(ans, here);
        }
        seen[at] = false;
        return ans;
    };

    auto bfs = [&](int at) -> vector<int> {
        vector<int> dist(n, 1e9);
        queue<int> q;
        dist[at] = 0;
        q.push(at);
        while (q.size()) {
            int here = q.front();
            q.pop();
            for (auto& e : tree[here]) {
                if (dist[e] > dist[here] + 1) {
                    dist[e] = dist[here] + 1;
                    q.push(e);
                }
            }
        }
        return dist;
    };

    int start = dfs(0).second;
    int end = dfs(start).second;

    auto a = bfs(start);
    auto b = bfs(end);

    for (int i = 0; i < n; i++) {
        cout << max(a[i], b[i]) << " \n"[i == n - 1];
    }
}