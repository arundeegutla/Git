#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    ll tot = 0;
    ll maxx = 0;
    while(n--){
        ll h = nextInt();
        ll w = nextInt();
        tot += min(h, w);
        maxx = max(maxx, max(h, w));
    }
    cout << max(tot, maxx) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}