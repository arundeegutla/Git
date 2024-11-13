#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    ll m = nextInt();
    ll n = nextInt();
    for(int i = 1; i <= n; i++){
        int x = nextInt();
        m -= x;
        if(m < 0) {
            cout << i - 1 << "\n";
            return;
        }
        if(m == 0) {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}