#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt(), c = nextInt();
    vector<int> dist(n);
    for(auto& x : dist) x = nextInt();
    for(int i = 0; i < n; i++)
        dist[i] += i+1;
    
    sort(dist.begin(), dist.end());

    ll count = 0;
    int hav = 0;
    for(int i = 0; i < n && count+dist[i] <= c; i++){
        count += dist[i];
        hav++;
    }
    cout << hav << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}