#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    string scores = next();
    auto x = scores.find_first_of(':');
    int egypt = stoi(scores.substr(0, x));
    int ghana = stoi(scores.substr(x+1));

    if(egypt+1 > ghana+6) {
        cout << "YES\n"; 
    } else if (ghana+6 > egypt+1) {
        cout << "NO\n"; 
    } else {
        if(2+egypt > (2*(ghana))+6)
            cout << "YES\n"; 
        else if(2+egypt < (2*(ghana))+6)
            cout << "NO\n"; 
        else
        cout << "PENALTIES\n"; 
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("ghanophobia.in", "r", stdin);
    int n = nextInt();
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}