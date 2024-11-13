#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> ppl(n);
    for(auto& [time, cash] : ppl)
        cin >> cash >> time;

    sort(all(ppl));

    vvi memo(n, vi(m+1, -1));
    auto go = [&](int at, int time, auto&& go) -> ll {
        if(time > m) return -1e10;
        if(at == n) return 0;

        auto& ans = memo[at][time];
        if(ans!=-1) return ans;

        ll leave = go(at+1, time, go);
        ll take = -1e10;
        if(time <= ppl[at].first)
            take = go(at+1, time+1, go) + ppl[at].second;

        return ans = max(take, leave);

    };

    cout << go(0, 0, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}