#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, d;
    cin >> n >> d;
    ll BAD = 1e10;
    vector<ll> mess(n);
    vector<ll> clean(n);
    for(int i = 0; i < n; i++){
        cin >> mess[i];
        cin >> clean[i];
    }
    vector<bool> parents(n);
    while(d--) {
        int x;
        cin >> x, x--;
        parents[x] = true;
    }

    vvi memo(n, vi(n+1, -1));

    auto go = [&](int at, int numCleans, auto&& go) -> ll {
        if(numCleans < 0) return BAD;
        if(at == -1) return 0;

        auto& ans = memo[at][numCleans];
        if(ans!=-1){
            // cout << "memo!\n";
            return ans;
        } 

        ll cleanhere = max(0LL, go(at-1, numCleans - 1, go) + mess[at] - clean[at]);
        ll dontClean = max(0LL, go(at-1, numCleans, go) + mess[at]);

        ll minn = min(cleanhere, dontClean);
        if(parents[at] && minn != 0) return ans = BAD;

        return ans = minn;

    };

    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        // if this many cleans could do it.
        ll mess = go(n-1, mid, go);
        // cout << mid << " " << mess << " " << BAD << "\n";

        if(mess < 1e9) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}