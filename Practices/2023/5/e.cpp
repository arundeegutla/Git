#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<int> tasks(n);
    for(auto& x : tasks) cin >> x;

    vvvi memo(n, vvi((1<<4), vi(4, -1)));
    auto go = [&](int at, int dropped, int cur, auto&& go) -> ll {
        if((dropped & (1<<cur)) != 0) return -1e10;
        if(at == n) return 0;



        auto& ans = memo[at][dropped][cur+1];
        if(ans != -1) {
            return ans;
        }

        if(cur == -1) {
            ll maxx = go(at, dropped, 0, go);
            maxx = max(maxx, go(at, dropped, 1, go));
            maxx = max(maxx, go(at, dropped, 2, go));
            return ans = maxx;
        }

        // cout << at << " " << bitset<4>(dropped).to_string() << " " << cur << "\n"; 

        // drop it and use new
        if(tasks[at] != cur) {
            ll drop = go(at+1, dropped | (1<<cur), tasks[at], go) + 1;
            ll skip = go(at+1, dropped, cur, go);
            return ans = max(drop, skip);
        }

        return ans = go(at+1, dropped, cur, go) + 1;
    };


    cout << go(0, 0, -1, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}