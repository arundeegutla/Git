#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        graph[a].push_back(c);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}