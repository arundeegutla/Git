#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    int k; cin >> k;
    if(n%k!=0) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    cout << 2 << endl;
    cout << (n-1) << " " << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}