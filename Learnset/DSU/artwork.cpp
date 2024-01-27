#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> size, parent;
    unordered_set<int> whiteRoots;

    DSU(int n) : n(n) {
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
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        whiteRoots.erase(b);
        whiteRoots.insert(a);
        if (a == b) return false;
        size[a] += size[b];
        return true;
    }

    int numRegions() {
        return whiteRoots.size();
    }
};

int main() {
    int n, m, q;
    cin >> m >> n >> q;
    vector<array<int, 4>> strokes(q);
    vector<vector<int>> canvas(n, vector<int>(m));
    vector<vector<bool>> used(n, vector<bool>(m));

    for (auto& arr : strokes) {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        arr[0]--, arr[1]--, arr[2]--, arr[3]--;
        for (int r = min(arr[1], arr[3]); r <= max(arr[1], arr[3]); r++)
            for (int c = min(arr[0], arr[2]); c <= max(arr[0], arr[2]); c++)
                canvas[r][c]++;
    }

    DSU dsu(n * m + 100);
    const int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    auto get = [&](int r, int c, auto&& get) -> void {
        used[r][c] = true;
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m) continue;
            if (canvas[nR][nC] || used[nR][nC]) continue;
            dsu.join(r * m + c, nR * m + nC);
            get(nR, nC, get);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!canvas[i][j] && !used[i][j]) {
                dsu.join(i * m + j, i * m + j);
                get(i, j, get);
            }
        }
    }

    vector<int> ans;
    ans.push_back(dsu.numRegions());
    while (strokes.size()) {
        auto arr = strokes.back();
        strokes.pop_back();

        for (int r = min(arr[1], arr[3]); r <= max(arr[1], arr[3]); r++) {
            for (int c = min(arr[0], arr[2]); c <= max(arr[0], arr[2]); c++) {
                canvas[r][c]--;
                if (canvas[r][c] != 0) continue;
                dsu.join(r * m + c, r * m + c);
                for (auto d : D) {
                    int nR = r + d[0];
                    int nC = c + d[1];
                    if (nR < 0 || nR >= n || nC < 0 || nC >= m || canvas[nR][nC] != 0) continue;
                    dsu.join(r * m + c, nR * m + nC);
                }
            }
        }
        ans.push_back(dsu.numRegions());
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << "\n";
    }
}