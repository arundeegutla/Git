#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, r, b; cin >> n >> r >> b;


    auto go = [&](int r, int b, auto && go) -> int {
        if(b == 0 && r==0) return 0;
        if(r < 0 || b < 0) return n+1;

        int minn = n+1;
        for(int i = 1; i <= max(r, b); i++){
            minn = min(minn, max(go(r-i, b, go), i));
            minn = min(minn, max(go(r, b-i, go), i));
        }
        return minn;
    };

    cout << go(r, b, go) << "\n";



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}