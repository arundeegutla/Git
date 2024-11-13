#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> tree(n);

    vector<bool> seen(n);
    function<void(int)> dfs = [&](int at) -> void {
        seen[at] = true;
        for (auto x : graph[at]) {
            if (!seen[x]) {
                dfs(x);
                tree[at].push_back(x);
            }
        }
    };
    dfs(0);

    vector<vector<int>> memo(n, vector<int>(2, -1));
    function<int(int, bool)> go = [&](int at, bool canUse) -> int {
        auto& ans = memo[at][canUse];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        vector<int> useChild;
        vector<int> pickchild;
        for (auto x : tree[at]) {
            useChild.push_back(go(x, true));
            pickchild.push_back(go(x, false) + 1);
        }

        // have to pick a child.
        int total = accumulate(useChild.begin(), useChild.end(), 0);
        if (!canUse) {
            return ans = total;
        }
        int maxx = total;
        for (int i = 0; i < tree[at].size(); i++)
            maxx = max(maxx, total - useChild[i] + pickchild[i]);
        return ans = maxx;
    };

    cout << max(go(0, true), go(0, false)) << "\n";
}