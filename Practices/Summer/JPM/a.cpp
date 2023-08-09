#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    
    ll low = 4e5;
    ll high = 5e5;
    ll count = 0;
    for(ll three = 1; three <= high && three <= 2e9; three*=3){
        for(ll five = 1; five <= high && five <= 2e9; five*=5){
            ll both = three * five;
            if(both >= low && both <= high) count++;
            if(both > high) break;
        }
    }

    cout << count << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}