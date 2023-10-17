#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll r, f;
    cin >> r >> f;

    // more than half so flip again.
    int numFlips = (f/r) + (2 * (f%r) > r);
    cout << ((numFlips % 2 == 0) ? "up" : "down") << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}