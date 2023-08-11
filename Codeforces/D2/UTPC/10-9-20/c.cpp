#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    int startX = nextInt();
    int startY = nextInt();
    ll maxx = 0;
    while(n--){
        ll x = startX - nextInt();
        ll y = startY - nextInt();
        maxx = max(maxx, x*x + y*y);
    }
    cout << setprecision(10) << sqrtl(maxx) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}