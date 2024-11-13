#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
// #define int ll

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    map<int, multiset<string>> hmap;
    for (int i = 0; i < n; i++) {
        hmap[arr[i] >> 2].insert(bitset<32>(arr[i]).to_string());
    }
    map<int, queue<string>> hmap2;
    for (auto& [x, s] : hmap) {
        for (auto& c : s) {
            hmap2[x].push(c);
        }
    }

    for (auto& x : arr) {
        string l = hmap2[x >> 2].front();
        hmap2[x >> 2].pop();

        x = stoi(l, nullptr, 2);
    }

    for (auto x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}