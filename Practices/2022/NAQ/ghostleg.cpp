#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        edges.push_back({x, x + 1});
    }

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int at = i;
        for (auto [from, to] : edges) {
            if (from == at) {
                at = to;
            } else if (to == at) {
                at = from;
            }
        }
        arr[at] = i;
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << "\n";
}