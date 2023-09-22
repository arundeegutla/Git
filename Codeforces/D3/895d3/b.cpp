#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> trap(n);
    for(auto& x : trap){
        cin >> x.first;
        cin >> x.second;
    }

    sort(all(trap));

    int maxx = 1e9;
    for(auto x : trap){
        if(x.first > maxx) break;

        int canGo = x.first + ((x.second-1)/2);
        maxx = min(canGo, maxx);
    }

    cout << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}