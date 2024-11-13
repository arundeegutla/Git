#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int c = n;
    map<int, int> hmap;
    for(int i = 1; i <= n; i++)
        hmap[nextInt()]++;

    int extras = 0;
    for(auto [k, v] : hmap)
        extras += v-1;

    

    cout << (n-extras) - (extras%2) << "\n";
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}