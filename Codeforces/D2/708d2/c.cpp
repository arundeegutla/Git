#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    int k = nextInt();
    if(n == 4){
        cout << "1 1 2\n";
        return;
    }
    if(n%2){
        cout << n/2 << " " << n/2 << " " << 1 << "\n";
    } else {
        if((n/2)%2){
            cout << 2 << " " << (n/2)-1 << " " << (n/2)-1 << "\n";
        } else {
            cout << 2 << " " << (n/2)-2 << " " << (n/2) << "\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}