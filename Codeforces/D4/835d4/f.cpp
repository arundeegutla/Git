#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    ll n = nextInt(), c = nextLong(), d = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    
    for(int i = 1; i < n; i++)
        arr[i] += arr[i-1];

    auto can = [&](ll k) -> bool {
        ll times = d/k;
        ll mod = d%k;
        ll sum = arr[min(n, k)-1] * times;
        if(mod!=0) sum += arr[min(n, mod)-1];
        return sum >= c;
    };

    ll lo = 1;
    ll hi = 1e15;
    ll ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        if(can(mid)){
            lo = (ans = mid) + 1;
        } else
            hi = mid - 1;
    }


    if(ans == 1e15){
        cout << "Infinity" << '\n';
    } else if (ans == -1){
        cout << "Impossible" << '\n';
    } else {
        cout << ans-1 << "\n";
    }



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}