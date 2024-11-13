#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& x : grid) cin >> x;

    string vika = "vika";
    int at = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            bool took = false;
            if(at < 4 && grid[j][i] == vika[at]){
                at++;
                took = true;
                break;
            }
            if(took) break;
        }
    }

    if(at == 4) cout << "YES" << "\n";
    else cout << "NO\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}