#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    // cout << "\n";
    // int index = 1;
    // ll cur = 0;
    // for(int i = 1; i <= 100; i++){
    //     cout << i << " ";
    //     for(int j = 1; j <= i; j++) 
    //         cout << (index++) << ":" << (cur += j) << " ";
    //     for(int j = i-1; j >= 1; j--) 
    //         cout << (index++) << ":" << (cur += j) << " ";
    //     cout << "\n";
    // }

    // getRow and getCol
    // sigma i^2 from 1 to getRow - 1
    // + sum of getCol

    auto go = [&](ll index) -> ll {
        ll row = ceil(sqrt((ld)index));
        ll p = row - 1;
        ll col = index - (p*p);
        ll numInRow = row + (row-1);

        // summation i^2 from 1 to row - 1
        ll sum = (((p*(p+1))/2LL) * ((2*p)+1)) / 3LL;
        if(col <= row) {
            sum += (col*(col+1))/2;
        } else {
            sum += (row*(row+1))/2;
            sum += ((row-1)*((row-1)+1))/2;
            ll sub = numInRow-col;
            sum -= (sub*(sub+1))/2;
        }

        // cout << row << " " << col << "\n";
        return sum;
    };
    // cout << go(9802) << "\n";

    ll n = nextLong();
    ll lo = 1;
    ll hi = 1e13;
    ll ans = -1;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll count = go(mid);

        if(count >= n) {
            hi = (ans = mid) - 1;
        } else if (count < n) {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("army.in", "r", stdin);
    int n = nextInt();
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}