#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for(auto& x : arr) cin >> x;

    vector<int> took(m);
    int cur = 0;
    while(cur < n) {
        bool changed = false;
        for(int i = 0; cur < n && i < m; i++){
            if(arr[i]) {
                took[i]++;
                arr[i]--;
                cur++;
                changed = true;
            }
        }
        if(!changed) break;
    }

    for(auto x : took) {
        cout << x << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}