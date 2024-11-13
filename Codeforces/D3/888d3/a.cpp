#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}


void solve() {
    ll n = nextInt(), m = nextInt(), k = nextInt(), h = nextInt();
    vector<ll> people(n);
    for(auto& x : people) x = nextInt();
    sort(people.begin(), people.end());

    int c = 0;
    for(auto x : people){
        bool done = false;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(i==j) continue;
                if(!done && ((k*i) - (k*j) == h-x)) {
                    c++;
                    done = true;
                }
            }
        }
    }

    cout << c << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}