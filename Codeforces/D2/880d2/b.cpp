#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextLong();
    ll k = nextLong();
    ll g = nextLong();  
    ll totalSilver = k*g;

    ll half = ceil(g/2.0);
    ll saved = (half-1)*(n-1);

    totalSilver -= saved;
    if((totalSilver%g) >= half) {
        saved -= (g-(totalSilver%g));
    } else {
        saved += totalSilver%g; 
    }
    cout << min(k*g, saved) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}