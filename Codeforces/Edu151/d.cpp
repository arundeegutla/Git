#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<ll> change(n);
    for(auto& x : change) x = nextLong();
    ll k = 0;
    ll maxx = 0;
    ll diff = 0;
    ll cur = 0;
    for(auto x : change){
        cur+=x;
        maxx = max(maxx, cur);
        if(diff < abs(maxx - cur)) {
            diff = abs(maxx - cur);
            k = maxx;
        }
    }
    cout << k << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}