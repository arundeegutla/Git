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
    int l = 0;
    int r = n-1;
    while(l < r){
        if(s[l] != s[r]){
            l++;
            r--;
        } else 
            break;
    }
    cout << (r - l)+1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}