#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        graph[x].push_back(i);
    }

    graph[0].push_back(1);
    vector<vector<int>> dp(n + 1, vector<int>(20, 0));
    vector<int> depth(n + 1, -1);

    auto dfs = [&](int a, auto&& dfs) -> void {
        for (auto b : graph[a]) {
            if (depth[b] != -1) continue;
            depth[b] = depth[a] + 1;
            dp[b][0] = a;
            for (int i = 1; i < 20; i++)
                dp[b][i] = dp[dp[b][i - 1]][i - 1];
            dfs(b, dfs);
        }
    };
    depth[0] = 0;
    dfs(0, dfs);
    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int i = 0; i < 20; i++)
            if ((k & (1 << i)) != 0)
                x = dp[x][i];

        if (x == 0) {
            cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }
    }
}