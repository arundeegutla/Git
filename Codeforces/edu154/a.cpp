#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string s; cin >> s;
    if(s[0] == '1') {
        cout << 13 << "\n";
        return;
    }
    if(s[0] == '2') {
        cout << 23 << "\n";
        return;
    }
    if(s[0] == '3') {
        cout << 31 << "\n";
        return;
    }
    if(s[0] == '4') {
        cout << 43 << "\n";
        return;
    }
    if(s[0] == '5') {
        cout << 53 << "\n";
        return;
    }
    if(s[0] == '6') {
        cout << 61 << "\n";
        return;
    }
    if(s[0] == '7') {
        cout << 71 << "\n";
        return;
    }
    if(s[0] == '8') {
        cout << 83 << "\n";
        return;
    }
    if(s[0] == '9') {
        cout << 97 << "\n";
        return;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}