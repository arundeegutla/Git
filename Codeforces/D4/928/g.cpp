#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 1; i < n; i++) {
        int to;
        cin >> to;
        to--;
        tree[i].push_back(to);
        tree[to].push_back(i);
    }

    string s;
    cin >> s;

    queue<int> q;
    vector<bool> seen(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            q.push(i);
            seen[i] = true;
        }
    }

    set<pair<int, int>> blocked;
    while (q.size()) {
        int here = q.front();
        q.pop();
        for (auto e : tree[here]) {
            if (seen[e]) continue;
            if (s[e] == 'P') {
                blocked.insert({here, e});
                blocked.insert({e, here});
            } else {
                q.push(e);
                seen[e] = true;
            }
        }
    }

    cout << blocked.size() / 2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}