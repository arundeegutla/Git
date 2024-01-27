#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll count = 0;
    for (ll power = 5; n / power >= 1; power *= 5) {
        count += n / power;
    }
    cout << count << "\n";
}