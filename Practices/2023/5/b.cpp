#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int h, k, v, s;
    cin >> h >> k >> v >> s;

    int x = 0;
    while(h > 0) {
        v += s;
        v -= max(1, v/10);
        if(v >= k) h++;
        else if (v > 0) {
            h--;
            if(h==0) {
                v = 0;
            }
        } else {
            h = 0;
            v = 0;
        }
        x += v;
        if(s) s--;
    }

    cout << x << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}