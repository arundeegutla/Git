#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
class RMQMAX {
public:
    int n;
    vector<vector<ll>> dp;
    // N(LOG N)
    RMQMAX(vector<ll> arr) {
        n = arr.size();
        dp.resize(n, vector<ll>(20));
        for(int i = 0; i < n; i++)
            dp[i][0] = arr[i];
        for(int LOG = 1; LOG < 20; LOG++)
            for(int i = 0; i + (1<<LOG) - 1 < n; i++)
                dp[i][LOG] = max(dp[i][LOG - 1], dp[i+(1<<(LOG-1))][LOG - 1]);
    }
    // O(1)
    ll query(int l, int r) {
        int len = r - l + 1;
        int LOG = 0;
        while((1<<(LOG+1)) <= len) LOG++;
        return max(dp[l][LOG], dp[r-(1<<LOG)+1][LOG]);
    }
};

class RMQMIN {
public:
    int n;
    vector<vector<ll>> dp;
    // N(LOG N)
    RMQMIN(vector<ll> arr) {
        n = arr.size();
        dp.resize(n, vector<ll>(20));
        for(int i = 0; i < n; i++)
            dp[i][0] = arr[i];
        for(int LOG = 1; LOG < 20; LOG++)
            for(int i = 0; i + (1<<LOG) - 1 < n; i++)
                dp[i][LOG] = min(dp[i][LOG - 1], dp[i+(1<<(LOG-1))][LOG - 1]);
    }
    // O(1)
    ll query(int l, int r) {
        int len = r - l + 1;
        int LOG = 0;
        while((1<<(LOG+1)) <= len) LOG++;
        return min(dp[l][LOG], dp[r-(1<<LOG)+1][LOG]);
    }
};


signed main(){
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    RMQMAX maxRMQ(arr);
    RMQMIN minRMQ(arr);

    ll tot = 0;
    int l = 0;
    for(int i = 0; i < n; i++){

        while(maxRMQ.query(l, i) - minRMQ.query(l, i) > k) l++;

        ll x = i - l + 1;

        tot += x;
    }

    cout << tot << "\n";

}