#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> m(n);
    vector<pair<int, int>> books(n);
    for(int i = 0; i < n; i++){
        m[i] = nextInt();
        string s = next();
        books[i] = {s[0]-'0', s[1]-'0'};
    }

    vvvi memo(n+1, vvi(2, vi(2, -1)));
    auto go = [&](int at, int f, int s, auto && go) -> ll {
        if(f && s) return 0;
        if(at == n) return 1e12;
        ll& ans = memo[at][f][s];
        if(ans != -1) return ans;
        ll read = go(at+1, f || books[at].first, s || books[at].second, go) + m[at];
        ll dont = go(at+1, f, s, go);
        return ans = min(read, dont);
    };

    ll ans = go(0, 0, 0, go);
    cout << (ans == 1e12 ? -1 : ans) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}