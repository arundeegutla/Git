#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int len = nextInt();
    string s = next();
    set<pair<char, char>> hset;
    for(int i = 0; i+1 < len; i++)
        hset.insert({s[i], s[i+1]});
    cout << hset.size() << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}