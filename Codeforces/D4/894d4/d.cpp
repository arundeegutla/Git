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
    vector<int> pref(n);
    vector<int> suff(n);
    unordered_set<char> p;
    for(int i = 0; i < n; i++){
        p.insert(s[i]);
        pref[i] = p.size();
    }

    unordered_set<char> suf;
    for(int i = n-1; i >= 0; i--){
        suf.insert(s[i]);
        suff[i] = suf.size();
    }

    int maxx = 0;
    for(int i = 0; i+1 < n; i++){
        maxx = max(maxx, pref[i] + suff[i+1]);
    }
    cout << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}