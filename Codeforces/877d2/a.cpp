#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    set<int> hset;
    for(int i = 0; i < n; i++) 
        hset.insert(nextInt());

    int maxx = 0;
    for(auto x : hset){
        maxx = max(maxx, x);
         if(x < 0){
            cout << x << "\n";
            return;
        }
    }
       
    cout << maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}