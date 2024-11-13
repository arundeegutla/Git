#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll 

void solve() {
    ll rounds, k;
    cin >> rounds >> k;

    int n = 1 << rounds;

    vector<ll> ratings(n);
    for(auto& x : ratings) cin >> x;
    sort(rall(ratings));

    int at = n-1;
    vector<set<int>> players(rounds+1);
    
    for(int i = 1; i <= rounds; i++) {
        for(int j = at; j > at/2; j--)
            players[i].insert(ratings[j]);
        at /= 2;
    }


    int count = 0;
    for(int i = 0; i < rounds; i++) {
        for(int playWith = rounds-i; playWith >= 1; playWith--){
            int cur = ratings[i];
            int need = cur - k;
            auto itr = players[playWith].lower_bound(need);
            
            assert(players[playWith].size());
            if(itr != players[playWith].end()) {
                // cout << ratings[i] << " is playing with " << *itr << "\n";
                players[playWith].erase(itr);
                count++;
            }
        }
    }

    cout << count << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}


/*

0 4
1 4

2 3
3 3

4 2
5 2
6 2
7 2

8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1

*/