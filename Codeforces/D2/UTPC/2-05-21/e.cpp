#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<vector<int>> grid(n, vector<int>(n));
    for(auto& arr : grid) for(auto& x : arr) x = nextInt();

    auto go = [&](int at, int mask, auto&& go) -> ll {
        if(at == n) return 0;

        ll maxx = 0;
        for(int i = 0; i < n; i++)
            if(!(mask&(1<<i)))
                maxx = max(maxx, go(at+1, mask|(1<<i), go) + grid[at][i]);
        return maxx;

    };

    cout << go(0, 0, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}