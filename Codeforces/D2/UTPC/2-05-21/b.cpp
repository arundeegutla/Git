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
    for(int i = 1; i <= n; i++){
        int x = nextInt();
        k -= x;
        if(k <= 0){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}