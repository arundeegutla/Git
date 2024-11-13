#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    map<int, int> hmap;

    for(int i = 0; i < n; i++) 
        hmap[nextInt()]++;

    ll maxx = 0;

    for(int x = 1; x <= n; x++){
        unordered_set<int> my;
        ll tot = 0;
        for(int i = 1; i*i <= x; i++){
            if(x%i==0) {
                if(my.insert(i).second){
                    tot += hmap[i];
                }
                if(my.insert(x/i).second){
                    tot += hmap[x/i];
                }
            }
        }
        if(my.insert(x).second){
            tot += hmap[x];
        }

        maxx = max(tot, maxx);

    }

    cout << maxx << "\n";
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}