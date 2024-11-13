#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

void solve() {
    auto power = [&](ll x, ll y) -> ll {
        ll res = 1;
        while (y > 0) {
            if (y % 2) {
                res *= x;
            }
            y >>= 1;
            x *= x;
        }
        return res;
    };

    string s;
    cin >> s;
    int n = s.size();
    string allVowels = "aeiouy";

    int vowels = -1;
    int cons = -1;

    int numOdd = 0, numEven = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i % 2) {
                numOdd++;
            } else
                numEven++;
            continue;
        }
        if (allVowels.find(s[i]) != allVowels.npos) {
            if (vowels == -1)
                vowels = i % 2;
            else if (vowels != (i % 2)) {
                cout << "0\n\n";
                return;
            }
        }
        if (allVowels.find(s[i]) == allVowels.npos) {
            if (cons == -1)
                cons = i % 2;
            else if (cons != (i % 2)) {
                cout << "0\n\n";
                return;
            }
        }
    }

    // cant be same parity.
    if (vowels != -1 && cons != -1 && vowels == cons) {
        cout << "0\n\n";
        return;
    }
    if (vowels != -1) {
        cons = !vowels;
    }

    if (cons != -1) {
        vowels = !cons;
    }
    ll ans = 0;
    if (vowels == -1) {
        ans += power(6, numEven) * power(20, numOdd);
        ans += power(6, numOdd) * power(20, numEven);

    } else {
        if ((vowels % 2) == 0) {
            ans += power(6, numEven) * power(20, numOdd);
        } else {
            ans += power(6, numOdd) * power(20, numEven);
        }
    }
    cout << ans << "\n\n";
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "String #" << i << ": ";
        solve();
    }
}