#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    ll tot = 0;
    int l = 0;
    map<int, int> count;
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
        while(count.size() > k) {
            count[arr[l]]--;
            if(!count[arr[l]]) count.erase(arr[l]);
            l++;
        }  
        ll x = max(0, (i-l+1));
        tot += x;
    }
    
    cout << tot << "\n";
}