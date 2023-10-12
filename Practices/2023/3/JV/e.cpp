#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string a, b;
    cin >> a >> b;

    ll count = 1;

    for(int i = 0; i < 4; i++)
        count *= 1 + (a[i] != b[i]);

    cout << count << "\n";
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}