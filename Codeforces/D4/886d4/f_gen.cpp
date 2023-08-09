#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    cout << 1 << '\n';
    int n = 2e5;
    cout << n << '\n';
    for(int i = 1; i <= n; i++)
        cout << i << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}