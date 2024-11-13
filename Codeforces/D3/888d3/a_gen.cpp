#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int t = 1000;
    cout << t << "\n";
    while(t--){
        int n = 50;
        int m = 50;
        cout << n << " " << m << " " << 1000000 << " " << 1000000 << "\n";
        for(int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        for(int i = 0; i < n; i++){
            cout << 1 << " ";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}