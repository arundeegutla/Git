#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve(int n) {

    int MOD = 1e8 + 7;

    vvi memo(n+1, vi(n+1, -1));
    auto go = [&](int need2, int need1, auto&& go) -> ll {
        if(need2 < 0 || need1 < 0) return 0;
        if(need1 == 0 && need2 == 0) return 1;

        auto& ans = memo[need2][need1];

        if(ans!=-1) {
            // cout << "memo!\n";
            return ans;
        }

        ll count = 0;
        // meet 2 new ppl.
        count += max(0LL, go(need2-2, need1+2, go) * (need2*(need2-1))/2);
        count %= MOD;
        // meet 2 already met ppl.
        count += max(0LL, go(need2, need1-2, go) * (need1*(need1-1))/2);
        count %= MOD;

        // meet 2 from each.
        count += max(0LL, go(need2-1, need1, go) * (need2*need1));
        count %= MOD;

        return ans = count;

    };

    cout << go(n, 0, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        solve(x);
    }
}