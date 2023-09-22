#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string s; cin >> s;
    bool a = s[0] == 'a';
    bool b = s[1] == 'b';
    bool c = s[2] == 'c';

    if(a || b || c) {
        cout << "YES" << "\n";
    } else {
        cout << "NO\n";
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}