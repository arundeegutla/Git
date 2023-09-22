#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

class RGCDQ {
public:
    int n;
    vector<vector<ll>> dp;
    // N(LOG N)
    RGCDQ(vector<ll> arr) {
        n = arr.size();
        dp.resize(n, vector<ll>(20));
        for(int i = 0; i < n; i++)
            dp[i][0] = arr[i];
        for(int LOG = 1; LOG < 20; LOG++)
            for(int i = 0; i + (1<<LOG) - 1 < n; i++)
                dp[i][LOG] = gcd(dp[i][LOG - 1], dp[i+(1<<(LOG-1))][LOG - 1]);
    }
    // O(1)
    ll query(int l, int r) {
        int len = r - l + 1;
        int LOG = 0;
        while((1<<(LOG+1)) <= len) LOG++;
        return gcd(dp[l][LOG], dp[r-(1<<LOG)+1][LOG]);
    }
};


signed main(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    RGCDQ range(arr);

    auto can = [&](int len) -> bool {
        for(int i = 0; i+len-1 < n; i++)
            if(range.query(i, i+len-1) == 1) 
                return true;
        return false;
    };

    int lo = 1;
    int hi = n;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo+hi) >> 1;
        if(can(mid)) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    
}