#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<string> grid(n);
    for(auto& x : grid) x = next();

    pair<int, int> a = {0, 0};
    pair<int, int> b = {0, n-1};
    pair<int, int> c = {n-1, n-1};
    pair<int, int> d = {n-1, 0};

    int at = 0;
    ll tot = 0;
    for(int i = 0; i < n/2; i++){
        int times = (b.second - a.second) + 1;
        for(int i = 0; i < times; i++) {
            int zeores = (grid[a.first][a.second] == '0') + (grid[b.first][b.second] == '0') + (grid[c.first][c.second] == '0') + (grid[d.first][d.second] == '0');
            int ones = (grid[a.first][a.second] == '1') + (grid[b.first][b.second] == '1') + (grid[c.first][c.second] == '1') + (grid[d.first][d.second] == '1');
            tot += min(zeores, ones);
            grid[a.first][a.second] = '-';
            grid[b.first][b.second] = '-';
            grid[c.first][c.second] = '-';
            grid[d.first][d.second] = '-';
            a.second++;
            b.first++;
            c.second--;
            d.first--;
        }
        at++;
        a = {at, at};
        b = {at, n-1-at};
        c = {n-1-at, n-1-at};
        d = {n-1-at, at};
    }
    cout << tot << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}