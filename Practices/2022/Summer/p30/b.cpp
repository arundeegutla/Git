#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll solve(){
    int MOD = 1e9 + 7;
    int n, k; cin >> n >> k;
    int ones = 0;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        ones += num;
    }

    vvi memo(n+1, vi(k+1, -1));
    auto go = [&](int o, int k, auto && go) -> ll {
        if(k==0) return !o;
        auto& ans = memo[o][k];
        if(ans != -1){
            // cout << "memo!\n";
            return ans;
        } 
        int ones1 = o;
        int zeroes = n-o;
        ll count = 0;
        if(ones1!=0){
            ll next = go(o-1, k-1, go);
            next *= ones1;
            next %= MOD;
            count += next;
            count %= MOD;
        }
        if(zeroes!=0){
            ll next = go(o+1, k-1, go);
            next *= zeroes;
            next %= MOD;
            count += next;
            count %= MOD;
        }
        return ans = count;
    };

    return go(ones, k, go);

}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cout << "Case #" << i << ": " << solve() << "\n";
    return 0;
}