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
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '1') {
                col[i]++;
            }
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        if (col[i] == 0 || col[i + 1] == 0) continue;
        if (col[i] != col[i + 1]) {
            cout << "TRIANGLE\n";
            return;
        }
    }

    cout << "SQUARE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}