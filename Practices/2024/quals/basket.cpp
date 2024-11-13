#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int team1 = 0;
    int team2 = 0;

    for (int i = 0; i < 3; i++) {
        int count;
        cin >> count;
        team1 += count * (i + 1);
    }
    for (int i = 0; i < 3; i++) {
        int count;
        cin >> count;
        team2 += count * (i + 1);
    }

    if (team1 > team2) {
        cout << 1 << "\n";
    } else if (team2 > team1) {
        cout << 2 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}