#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int ds, ys;
    cin >> ds >> ys;
    int dm, ym;
    cin >> dm >> ym;

    for(int i = 1; i <= 5000; i++){
        int distS = i + ds;
        int distM = i + dm;
        if((distS % ys == 0) && (distM % ym == 0)) {
            cout << i << "\n";
            return;
        }
    }


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}