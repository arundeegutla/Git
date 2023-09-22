#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    vector<ll> a;
    int prev = arr[0];
    for(auto x : arr){
        if(prev <= x){
            a.push_back(x);
        } else {
            a.push_back(x);
            a.push_back(x);
        }
        prev = x;
    }

    cout << a.size() << "\n";
    for(auto x : a) cout << x << " ";
    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}