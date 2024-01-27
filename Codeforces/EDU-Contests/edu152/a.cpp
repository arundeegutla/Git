#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll b = nextInt(), c = nextInt()+nextInt();
    
    if(b >= c+1){
        cout << c+1 + c << "\n";
        return;
    }
    if(c >= b-1){
        cout << b-1+b << "\n";
        return;
    }


    cout << 0 << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}