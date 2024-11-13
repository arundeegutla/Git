#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
int nextInt(){int a; cin >> a; return a;}

void solve(){
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    
    vvvi memo(n, vvi(4, vi(1<<4, -1)));
    auto go = [&](int at, int cur, int dropped, auto && go) -> int {
        if(at == n) return 0;
        int& ans = memo[at][cur+1][dropped];
        if(ans != -1) return ans;

        int tool = arr[at];
        int dont = go(at+1, cur, dropped, go);
        int take = 0;
        if(cur == -1)
            take = go(at+1, tool, dropped, go) + 1;
        else if (!(dropped & (1<<tool)) && cur == tool)
            take = go(at+1, cur, dropped, go) + 1;
        else if (!(dropped & (1<<tool)))
            take = go(at+1, tool, (dropped | (1<<cur)), go) + 1;
            
        return ans = max(dont, take);
    };

    cout << go(0, -1, 0, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}