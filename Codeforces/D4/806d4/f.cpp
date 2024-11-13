#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define int ll
void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    vector<ll> numPairs(n+1);

    ll p = 0;
    ll count = 0;
    for(int j = 1; j <= n; j++){
        if(arr[j-1]-1 >= 0 && arr[j-1]-1 < j && arr[j-1] < j){
            count += numPairs[arr[j-1]-1];
        }
        
        p += arr[j-1] < j;
        numPairs[j] = p;
    }

    cout << count << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}