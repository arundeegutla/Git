#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int m = nextInt();
    ll tsondu = 0, other = 0;
    for(int i = 0; i < n; i++) tsondu += nextLong();
    for(int i = 0; i < m; i++) other += nextLong();

    if(tsondu > other)
        cout << "Tsondu" << "\n";
    else if(other > tsondu) 
        cout << "Tenzing" << "\n";
    else    
        cout << "Draw\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}