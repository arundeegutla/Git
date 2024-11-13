#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    map<int, int> freq;
    for(auto x : arr) freq[x]++;

    multiset<int> hset;
    for(auto [_, v] : freq)
        hset.insert(-v);


    int cur = 0;
    for(auto x : hset){
        int have = -x;
        cur -= have;
        cur = abs(cur);
    }

    cout << cur << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}