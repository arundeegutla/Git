#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), k = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();

    vector<vector<ll>> memo(n, vector<ll>(35, -1));
    auto go = [&](int at, int times, auto && go) -> ll {
        if(times > 30) return 0;
        if(at == n) return 0;
        auto& ans = memo[at][times];
        if(ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        ll buy = go(at+1, times, go) - k + (arr[at] >> times);
        ll halve = go(at+1, times+1, go) + (arr[at] >> (times+1));
        return ans = max(buy, halve);
    };
    cout << go(0, 0, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}