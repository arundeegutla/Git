#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    ll sum = 0;
    vector<int> arr(n);
    for(auto& x : arr) sum += x = nextInt();

    if(n==1) {
        cout << "NO\n";
        return;
    }

    sort(all(arr));
    reverse(all(arr));

    ll changed = 0;
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(cur == 1) break;
        changed += min(cur, n-i);
        if(changed >= n) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}