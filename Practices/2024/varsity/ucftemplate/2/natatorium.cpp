#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ll a, n;
    cin >> a >> n;

    set<ll> primes;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        primes.insert(k);
    }

    for (ll p : primes) {
        if (a % p)
            continue;
        ll p2 = a / p;
        if (p2 == p)
            continue;
        if (primes.count(p2)) {
            cout << p << ' ' << p2;
            break;
        }
    }

    return 0;
}