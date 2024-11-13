#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    string L = next();
    string R = next();
    while(L.size() != R.size()) L.insert(0, "0");

    int at = 0;
    while (at < L.size() && L[at] == R[at]) at++;
    if(at == L.size()){
        cout << 0 << "\n";
        return;
    }

    ll tot = (R[at]-L[at]) + 9 * (L.size()-(at+1));
    cout << tot << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}