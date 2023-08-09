#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int nextInt(){int a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    int maxx = LLONG_MIN;
    for(auto& x : arr) 
        maxx = max(maxx, x = nextInt());

    if(n <= 2) {
        cout << maxx << "\n";
        return;
    }

    int pref = INT_MIN;
    for(int i = 0; i < n; i+=2) {
        pref = max(pref, max(arr[i], pref + arr[i]));
        maxx = max(maxx, pref);
    }

    pref = INT_MIN;
    for(int i = 1; i < n; i+=2) {
        pref = max(pref, max(arr[i], pref + arr[i]));
        maxx = max(maxx, pref);
    }
    cout << maxx << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}