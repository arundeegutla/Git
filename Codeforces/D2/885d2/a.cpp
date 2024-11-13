#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt(), m = nextInt(), k = nextInt();
    pair<int, int> vika = {nextInt(), nextInt()};

    vector<pair<int, int>> friends;
    while(k--)
        friends.push_back({nextInt(), nextInt()});
    
    bool can = true;
    for(auto f : friends)
        if((abs(vika.first - f.first) + abs(vika.second-f.second)) % 2 == 0)
            can = false;

    
    cout << (can ? "YES" : "NO") << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}