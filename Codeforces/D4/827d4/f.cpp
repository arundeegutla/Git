#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define int ll
// check for int overflow.
void solve() {
    int q = nextInt();
    map<char, ll> s;
    map<char, ll> t;
    s['a']++;
    t['a']++;
    while(q--){
        int x = nextInt();

        if(x == 1){
            int k = nextInt();
            string l = next();
            for(auto c : l) s[c] += k;
        }
        if(x == 2){
            int k = nextInt();
            string l = next();
            for(auto c : l) t[c] += k;
        }

        char c = 'z';
        while(!s[c]) c--;
        char p = 'z';
        while(!t[p]) p--;
        
        if(p != 'a' || (s['a'] < t['a'] && c == 'a') || (s['a'] == t['a'] && p != 'a')) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}