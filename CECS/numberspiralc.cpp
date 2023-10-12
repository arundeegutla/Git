#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll r, c;
    cin >> r >> c;
    ll ans = max(r, c) - 1;
    ans *= ans;

    ll major = max(r, c);
    if(r == major) {
        if(r % 2) {
            cout << ans + c << "\n";
            return;
        }
        ans += major;
        ans += major - c;
        cout << ans << "\n";
        return;
    }


    if(c % 2) {
        ans += major;
        ans += major - r;
        cout << ans << "\n";
        return;
    }

    cout << ans + r << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}