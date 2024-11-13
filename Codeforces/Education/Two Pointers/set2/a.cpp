#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, s;
    cin >> n >> s;

    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    auto can = [&](int len) -> bool {

        ll sum = 0;
        for(int i = 0; i < len; i++)
            sum += arr[i];

        if(sum <= s) return true;

        for(int i = len; i < n; i++){
            sum -= arr[i-len];
            sum += arr[i];
            if(sum <= s) return true;
        }
        return false;
    };

    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo+hi) >> 1;
        if(can(mid)) {
            lo = (ans = mid) + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}