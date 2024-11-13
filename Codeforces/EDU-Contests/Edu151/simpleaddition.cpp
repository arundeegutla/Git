#include <bits/stdc++.h>
using namespace std;
string next(){string a; cin >> a; return a;}

void solve() {
    string a = next(), b = next();
    if(a.size()<b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    b.resize(a.size(), '0');

    int carry = 0;
    string ans;
    for(int i = 0; i < a.size(); i++){
        int add = carry+a[i]+b[i]-'0'-'0';
        ans += (add % 10) + '0';
        carry = add / 10;
    }
    if(carry != 0) ans += carry + '0';
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}