#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());
    ll minn = 1e18;
    for(int i = 0; i+2 < n; i++) {
        int a = arr[i];
        int mean = arr[i+1];
        int c = arr[i+2];
        minn = min(minn, (ll) abs(a-mean) + abs(c-mean));
    }
    cout << minn << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}