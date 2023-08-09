#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    unordered_map<ll, int> hmap;
    ll count = 0;
    ll pref = 0;
    for(int x : arr) {
        hmap[pref]++;
        pref += x;
        count += hmap[pref - 47];
    }
    cout << count << "\n";
}

int main(){
    int n; cin >> n;
    while(n--) solve();
}