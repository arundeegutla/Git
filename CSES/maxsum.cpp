#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;


    if(*(max_element(all(arr))) <= 0) {
        cout << *(max_element(all(arr))) << "\n";
        return;
    }

    ll maxx = -1e18;
    ll sum = 0;
    for(auto x : arr) {
        sum += x;
        if(sum < 0) sum = 0;
        maxx = max(maxx, sum);
    }

    cout << maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}