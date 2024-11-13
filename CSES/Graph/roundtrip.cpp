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

    int found = -1;
    vector<int> path;
    vector<int> seen(n);
    function<bool(int, int)> go = [&](int at, int p) -> bool {
        if (seen[at]) {
            found = at;
            path.push_back(at);
            return true;
        }

        seen[at] = true;
        for (auto e : graph[at]) {
            if (e == p) continue;
            if (go(e, at)) {
                if (found != -1) {
                    path.push_back(at);
                    if (found == at) {
                        found = -1;
                    }
                }
                return true;
            }
        }
        return false;
    };

    bool check = false;
    for (int i = 0; i < n && !check; i++) {
        check |= !seen[i] ? go(i, -1) : false;
    }
    if (path.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << path.size() << "\n";
    for (auto x : path) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}
