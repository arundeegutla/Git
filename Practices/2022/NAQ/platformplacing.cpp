#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, k;
    cin >> n >> s >> k;

    vector<pair<int, pair<int, int>>> dist;
    vector<int> points(n);
    for (auto& x : points) cin >> x;

    for (int i = 0; i + 1 < n; i++)
        dist.push_back({points[i + 1] - points[i], {i, i + 1}});
    sort(dist.begin(), dist.end());

    if (dist[0].first < s) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> fixed(n);
    for (auto [d, e] : dist) {
        auto [x, y] = e;
        int leftDist = x == 0 ? 1e9 : points[x] - points[x - 1];
        int rightDist = y == n - 1 ? 1e9 : points[y + 1] - points[y];

        if (rightDist >= leftDist) {
            int maxCanReach = y == n - 1 ? 1e9; : points[y + 1] ;
        }
    }
}