#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;

    set<pair<int, int>> vals;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        auto& x = arr[i];
        cin >> x;
        vals.insert({x, i});
    }


    vector<int> b(n);
    int cur = n;
    for(auto [k, v] : vals){
        b[v] = cur--;
    }

    for(auto x : b)
        cout << x << " ";

    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}
