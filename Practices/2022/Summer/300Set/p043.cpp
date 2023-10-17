#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    int m = nextInt();
    ll k = nextLong();
    
    vector<int> perm(n);
    for(int i = 0; i < n; i++)
        perm[i] = i+1;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}