#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), k = nextInt(), x = nextInt();

    if(x!=1){
        cout << "YES" << "\n";
        cout << n << "\n";
        for(int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        cout << "\n";
        return;
    }

    if(!(n%2) && k >= 2) {
        cout << "YES" << "\n";
        cout << n/2 << "\n";
        for(int i = 0; i < n/2; i++){
            cout << 2 << " ";
        }
        cout << "\n";
        return;
    }

    if((n%2) && k >= 3) {
        cout << "YES" << "\n";
        cout << n/2 << "\n";
        for(int i = 0; i < (n/2 )- 1; i++){
            cout << 2 << " ";
        }
        cout << 3;
        cout << "\n";
        return;
    }

    cout << "NO\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}