#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    vector<ll> cat(5001);
    cat[0] = 1;
    for(ll i = 1; i <= 5000; i++){
        cat[i] = cat[i-1];
        cat[i] *= (4*i-2);
        cat[i] /= (i+1);
    }
    int n = nextInt();
    while(n--) 
        cout << cat[nextInt()] << "\n";
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}