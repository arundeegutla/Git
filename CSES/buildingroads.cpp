#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> seen(n);
    function<void(int)> dfs;
    dfs = [&](int at) -> void {
        if (seen[at]) return;
        seen[at] = true;
        for (auto e : graph[at]) {
            dfs(e);
        }
    };

    int head = -1;
    vector<pair<int, int>> roads;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(i);
            if (head != -1)
                roads.push_back({head + 1, i + 1});
            head = i;
        }
    }

    cout << roads.size() << "\n";
    for (auto [a, b] : roads) {
        cout << a << " " << b << "\n";
    }
}