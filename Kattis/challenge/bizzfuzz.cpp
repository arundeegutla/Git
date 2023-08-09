#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll nextLong(){ll a; cin >> a; return a;}
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
ll lcm(ll a, ll b) { return (a*b) / gcd(a, b) ;}

void solve() {

    ll a = nextLong(), b = nextLong(), c = nextLong(), d = nextLong();
    auto numbersDivisible = [&](ll x) -> ll {
        return x/(lcm(c, d));
    };

    ll tot = numbersDivisible(b) - numbersDivisible(a-1);
    cout << tot << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}