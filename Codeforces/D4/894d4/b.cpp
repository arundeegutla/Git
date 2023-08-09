#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    string s = next();

    int x = 0;
    int y = 0;
    for(auto c : s){
        if(c=='R'){
            x++;
        }
        if(c == 'L')
            x--;
        if(c == 'U')
            y++;
        if(c == 'D')
            y--;
        if(x == 1 && y == 1){
            cout <<  "YES\n";
            return;
        }
    }

    cout << "no\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}