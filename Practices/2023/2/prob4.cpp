#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;

    cout << n << "\n";

    set<ll> factors;
    while(m--){
        int x; cin >> x;
        for(int i = 2; i * i <= x; i++){
            while(x%i==0){
                factors.insert(i);
                x/=i;
            }
        }
        if(x >= 2) factors.insert(x);
    }

    vector<ll> fac(all(factors));
    for(int i = 1; i <= fac.size(); i++){
        cout << fac[i-1] << " ";
        if(i != fac.size() && i % 5 == 0) cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}