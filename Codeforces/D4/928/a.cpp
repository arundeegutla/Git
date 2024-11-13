#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s;
    cin >> s;
    map<char, int> freq;
    for (auto c : s) freq[c]++;
    if (freq['A'] >= freq['B']) {
        cout << 'A' << "\n";
    } else {
        cout << 'B' << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}