#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n, vector<int>(n, 1e18));
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (dist[a][b] == 1e18)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }
}