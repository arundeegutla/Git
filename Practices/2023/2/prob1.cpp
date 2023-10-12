#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve(string n) {
    ll tot = 0;
    for(int i = 0; i < n.size(); i++){
        tot += (int)pow(n[i]-'0', i+1);
    }
    string s = to_string(tot);
    cout << n << " is" << ((s == n) ? " a" : " not a") << " powerful number.\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    while(true){
        string n;
        cin >> n;
        if(n == "0") return 0;
        solve(n);
    }
}