#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        tree[a].push_back(i);
    }

    vector<int> ans(n);
    auto dfs = [&](int at, auto&& dfs) -> int {
        int count = 0;
        for (auto e : tree[at]) {
            count++;
            count += dfs(e, dfs);
        }
        return ans[at] = count;
    };
    dfs(0, dfs);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
