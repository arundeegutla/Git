#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    int MOD = 1e9 + 7;

    vector<vector<ll>> memo(n, vector<ll>(100, -1));
    auto go = [&](int at, int myAnd, auto && go) -> ll {
        if(at == n) return 0;
        ll& ans = memo[at][myAnd];
        if(ans!=-1)return ans;
        ll count = 0;
        count += go(at+1, myAnd&arr[at], go) + (bitset<10>(myAnd&arr[at]).count() == k);
        count %= MOD;
        count += go(at+1, myAnd, go);
        count %= MOD;
        return ans = count;
    };

    cout << go(0, (1<<6)-1, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}