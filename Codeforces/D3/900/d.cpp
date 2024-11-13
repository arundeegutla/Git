#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> l(k);
    vector<int> r(k);
    for(auto& x : l)cin >> x;
    for(auto& x : r)cin >> x;


    set<pair<int, int>> segs;
    for(int i = 0; i < k; i++)
        segs.insert({r[i], l[i]});

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;

        auto [left, right] = *segs.lower_bound({x, 0});

        int a = min(x, right + left - x);
        int b = max(x, right + left - x);

        a--;
        b--;

        reverse(s.begin()+a, s.begin()+b+1);
    }


    cout << s << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}