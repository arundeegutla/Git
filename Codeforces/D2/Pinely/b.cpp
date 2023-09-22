#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    vector<int> ind(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ind[x-1] = i;
    }

    int count = 0;
    for(int i = 1; i < n; i++)
        count += ind[i] < ind[i-1];
        
    cout << count << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}