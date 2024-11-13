#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    vector<int> team(n, -1);

    function<bool(int, int)> go = [&](int at, int t) -> bool {
        if (team[at] != -1)
            return team[at] != t;
        team[at] = t;
        bool flg = false;
        for (auto e : graph[at]) {
            flg |= go(e, (t + 1) % 2);
        }
        return flg;
    };

    bool flg = false;

    for (int i = 0; i < n; i++) {
        if (team[i] == -1) {
            flg |= go(i, 0);
        }
    }

    if (flg) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x : team) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}