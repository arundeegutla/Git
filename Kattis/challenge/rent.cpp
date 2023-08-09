#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll a = nextInt(), b = nextInt();
    ll m = nextInt(), phi = nextInt();

    // xxxxxxyyyyyy = m
    // (choose some x and 2 times) + remainder in m >= phi
    // choose x for all and price for one x is less BAD
    // choose y for all and will be less than phi BAD

    if(a >= b) {
        cout << (m-1)*a + b<< "\n";
        return;
    }

    for(ll i = 1; i <= m; i++){
        if((2*i)+(m-i) >= phi){
            cout << a*i + b*(m-i) << "\n";
            return;
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}