#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    vector<string> grid(10);
    for(auto& x : grid) cin >> x;

    
    auto go = [&](int startR, int startC, int dist, int points) -> ll {
        ll here = 0;


        
        int endR = startR+dist;
        int endC = startC+dist;

        for(int i = startC; i <= endC; i++){
            here += grid[startR][i] == 'X';
            grid[startR][i] = '-';
        }

        for(int i = startR; i <= endR; i++){
            here += grid[i][endC] == 'X';
            grid[i][endC] = '-';
        }

        for(int i = endC; i >= startC; i--){
            here += grid[endR][i] == 'X';
            grid[endR][i] = '-';

        }

        for(int i = endR; i >= startR; i--){
            here += grid[i][startC] == 'X';
            grid[i][startC] = '-';

        }

        return here * points;

    };

    ll tot = 0;

    tot += go(0, 0, 9, 1);
    tot += go(1, 1, 7, 2);
    tot += go(2, 2, 5, 3);
    tot += go(3, 3, 3, 4);
    tot += go(4, 4, 1, 5);


    cout << tot << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}