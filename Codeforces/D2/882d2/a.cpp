#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), k = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    vvi memo(n, vi(k+1, -1));
    auto go = [&](int at, int need, auto && go) -> ll {
        if(need < 0) return 1e12;
        if(at == n)
            return need == 0 ? 0 : 1e12;
        ll& ans = memo[at][need];
        if(ans != -1)return ans;
        ll minn = 1e12;
        ll sum = 0;
        for(int i = at; i < n; i++) {
            if(i > at) sum += abs(arr[i-1]-arr[i]);
            minn = min(minn, sum + go(i+1, need-1, go));
        }
        return ans = minn;
    };

    cout << go(0, k, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}