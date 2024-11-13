#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> seen(n);
    function<pair<int, int>(int)> dfs = [&](int at) -> pair<int, int> {
        if (seen[at]) return {-1, -1};
        seen[at] = true;
        pair<int, int> ans = {0, at};
        for (auto& e : tree[at]) {
            auto here = dfs(e);
            here.first += 1;
            ans = max(ans, here);
        }
        seen[at] = false;
        return ans;
    };

    int start = dfs(0).second;
    cout << dfs(start).first << "\n";
}