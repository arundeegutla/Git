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

    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    ll x = 0;
    ll y = 0;
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < n; i += 2) {
        x += arr[i];
        left.push_back(x);
    }
    for (int i = 1; i < n; i += 2) {
        y += arr[i];
        right.push_back(y);
    }

    for (auto& z : left) {
        cout << z << " ";
    }
    cout << "\n";

    for (auto& z : right) {
        cout << z << " ";
    }
    cout << "\n";

    cout << "\n";

    // get substring from l - r
    // 1 2 3 4 5 6 7 8 9 10
    // |___________|
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}