#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll n, m, d; cin >> n >> m >> d;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    //  choose the last element which gives the maxx.
    // hit or miss, u add D anyway.
    ll maxx = 0;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < n; i++){
        if(arr[i] <= 0) continue;
        if(pq.size() == m){
            sum -= pq.top(); 
            pq.pop();
        }
        pq.push(arr[i]);
        sum += arr[i];
        ll here = sum - (d*(i+1));
        maxx = max(maxx, here);
    }

    cout << maxx << "\n";
    



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}