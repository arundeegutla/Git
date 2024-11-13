#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long int;

void solve() {
    string s; cin >> s;
    set<char> myset;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        myset.emplace(s[i]);
        myset.emplace(s[j]);
    }
    if (myset.size() >= 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
