#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    ll x = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextLong();

    ll psum = 0;
    set<pair<ll, ll>> prev;
    ll minn = 1e18;
    
    auto check = [&](ll need, ll i) -> void {
        auto itr = prev.lower_bound({need, i});
        if(itr == prev.begin()) return;
        itr--;
        minn = min(minn, (i - (*itr).second));
    };

    auto removeBigger = [&](ll psum, int i) -> void {
        auto itr = prev.upper_bound({psum, -1});
        prev.erase(itr, prev.end());
        prev.insert({psum, i});
    };

    for(int i = 0; i < n; i++){
        int k = arr[i];
        psum += k;
        ll need = psum - x;
        check(need, i);
        removeBigger(psum, i);
    }

    cout << (minn==1e18 ? -1 : minn) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}