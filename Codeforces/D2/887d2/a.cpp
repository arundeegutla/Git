#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();

    ll minn = 1e18;
    for(int i = 0; i+1 < n; i++)
        minn = min(minn, arr[i+1] - arr[i]);

    cout << max(0LL, (minn >> 1) + 1) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}