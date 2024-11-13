#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();

    // store count of points.
    map<int, ll> pos;
    map<int, ll> neg;
    map<int, ll> x;
    map<int, ll> y;
    
    ll ans = 0;
    while(n--){
        int r = nextInt(), c = nextInt();

        ans += 2*x[r];
        ans += 2*y[c];
        ans += 2*pos[r+c];
        ans += 2*neg[r-c];

        x[r]++;
        y[c]++;
        pos[r+c]++;
        neg[r-c]++;

    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}