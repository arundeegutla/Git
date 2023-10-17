#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    vector<ll> price = {7,27,41,49,63,78,108};
    map<int, int> coupons;
    coupons[69] = 15;
    coupons[89] = 30;
    coupons[120] = 50;

    int n = nextInt();
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += price[nextInt()-1];
    
    auto it = coupons.upper_bound(sum);
    if(it != coupons.begin())
        cout << sum - (*it).second << " " << it->second << "\n";
    else 
        cout << sum << "\n";
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}