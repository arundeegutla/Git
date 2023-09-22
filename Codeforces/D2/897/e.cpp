#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    set<pair<int, int>> ps;
    for(int i = 0; i < n; i++){
        ps.insert({i+1, arr[i]});
    }

    

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}