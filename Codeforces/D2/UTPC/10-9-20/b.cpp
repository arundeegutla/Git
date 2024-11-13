#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    ll bronze = 0;
    ll gold = 0;
    ll silver = 0;
    while(n--){
        string s; cin >> s;
        if(s == "gold"){
            if(silver > 0 && bronze > 0){
                bronze--;
                silver--;
                gold++;
            } else if(bronze >= 3){
                bronze -= 3;
                gold++;
            } else {
                cout << "NO\n";
                return;
            }
        } else if(s == "silver"){
            if(bronze > 0) {
                bronze--;
                silver++;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            bronze++;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}