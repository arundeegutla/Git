#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextInt(), d = nextInt(), h = nextInt();
    vector<int> base(n);
    for(auto& x : base) x = nextInt();
    reverse(base.begin(), base.end());

    ll prev = 1e18;
    ld tot = 0;
    for(auto x : base){
        // Add the triangle and remove the intersection.
        tot += (d*h);
        if(x+h > prev){
            ld inHeight = h - (prev-x);
            ld baseOfIntersection = d * (inHeight/h);
            tot -= baseOfIntersection*inHeight;
        }
        prev = x;
    }

    cout << setprecision(10) << tot/2 << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}