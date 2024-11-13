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
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    if(!(n%2)) {
        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
        return;
    }

    cout << 4 << "\n";
    cout << 1 << " " << n-1 << "\n";
    cout << 1 << " " << n-1 << "\n";
    cout << 2  << " " << n << "\n";
    cout << 2  << " " << n << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}