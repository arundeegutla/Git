#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size();

    bool prevZero = 0;
    bool gottaChange = false;
    for(int i = 0; i < n; i++){
        if(a[i] == '0' && b[i] == '0'){
            if(gottaChange)
                gottaChange = false;
            prevZero = i;
        }
        if(a[i] == '1' && b[i] == '1')
            if(!gottaChange)
                break;
        if(a[i] != b[i]) gottaChange = true;
    }

    cout << (gottaChange ? "NO" : "YES") << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}