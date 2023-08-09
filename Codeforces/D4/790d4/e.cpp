#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    map<int, int> tMap;
    int sum = 0;
    for(int i = n-1; i >= 0; i--){
        sum += arr[i];
        tMap[sum] = n-i;
    }

    while(q--){
        int num; cin >> num;
        auto x = tMap.upper_bound(num-1);
        if(x != tMap.end()) {
            cout << (*x).second << "\n";
        } else {
            cout << -1 << "\n";
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}