#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

struct Flight {
    int start, end, from, to;
};

struct Plane {
    int time, at;
};

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> inspection(n);
    for (auto& x : inspection) cin >> x;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (i != j)
                graph[i][j] += inspection[j];
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    vector<Flight> flights;
    for (int i = 0; i < m; i++) {
        int s, f, t;
        cin >> s >> f >> t;
        s--, f--;
        flights.push_back({t, t + graph[s][f], s, f});
    }

    auto mySort = [&](Flight a, Flight b) -> bool {
        if (a.end == b.end) return a.start < b.start;
        return a.end < b.end;
    };

    sort(flights.begin(), flights.end(), mySort);

    vector<Flight> planes;

    for (auto flight : flights) {
        auto [start, end, from, to] = flight;
        }
}