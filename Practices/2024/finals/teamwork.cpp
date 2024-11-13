#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

pair<int, vi> hungarian(vector<vi>& a) {
    if(a.empty()) return {0, {}};
    int n = a.size() + 1;
    int m = a[0].size() + 1;
    vi u(n), v(m), p(m), ans(n - 1);
    for(int i = 1; i < n; i++) {
        p[0] = i;
        int j0 = 0;
        vi dist(m, INT_MAX), pre(m, -1);
        vector<bool> done(m + 1);
        do {
            done[j0] = true;
            int i0 = p[j0], j1, delta = INT_MAX;
            for(int j = 1; j < m; j++) {

                if(!done[j]) {
                    auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                    if(cur < dist[j]) dist[j] = cur, pre[j] = j0;
                    if(dist[j] < delta) delta = dist[j], j1 = j;
                }
            }
            for(int j = 0; j < m; j++) {
                if(done[j]) u[p[j]] += delta, v[j] -= delta;
                else dist[j] -= delta;
            }
            j0 = j1;

        } while (p[j0]);

        // cout << "here\n";
        while(j0) {
            // cout << j0 << "\n";
            int j1 = pre[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    for(int j = 1; j < m; j++) {
        if(p[j]) ans[p[j] - 1] = j - 1;
    }
    return {-v[0], ans};
}

signed main() {
    int n, p, t;
    cin >> n >> p >> t;
    vector<vi> grid(n, vector<int>(p, 1e9));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            int x;
            cin >> x;
            if(x == 0) continue;
            grid[i][j] = x;
        }
    }


    auto [c, arr] = hungarian(grid);
    
    vector<int> dist;
    for(int i = 0; i < n; i++) {
        dist.push_back(grid[i][arr[i]]);
    }

    sort(dist.begin(), dist.end());

    int sum = 0;
    int count = 0;
    for(auto x : dist) {
        if(sum + x <= t) {
            sum += x;
            count++;
        }
    }

    cout << count << "\n";
    
}