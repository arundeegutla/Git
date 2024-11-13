#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}


void solve() {
    int n = nextInt();
    int isiah = nextInt();
    int mina = nextInt();
    while(n > 0){
        int takeMina = gcd(n, mina);
        n -= takeMina;
        if(n < 0) {
            cout << 1 << "\n";
            return;
        }
        int takeIsiah = gcd(n, isiah);
        n -= takeIsiah;
        if(n < 0){
            cout << 0 << "\n";
            return;
        } 
    }
    cout << 1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}