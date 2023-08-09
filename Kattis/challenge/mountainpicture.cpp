#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
#define x first
#define y second

void solve() {
    int n = nextInt();
    int maxHeight = 0;
    pair<ld, ld> everest;
    vector<pair<ld, ld>> mountains(n);

    for (int i = 0; i < n; i++){
        mountains[i] = {i, nextInt()};
        if(mountains[i].second > maxHeight){
            everest = mountains[i];
            maxHeight = mountains[i].second;
        }
    }

    int h = mountains[0].second;
    ll lo = 0;
    ll hi = 1e17;
    int ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        ll x = -mid;
        ll y = h+4;
        ld m = (everest.y-y)/(everest.x-x);
        ld b = y - (((everest.y-y)*x)/(everest.x-x));

        // cout << lo << " "<< hi << "\n";
        bool works = true;
        for(int i = 0; i < everest.x; i++){
            auto mountain = mountains[i];
            if((m*mountain.x + b) - mountain.y <= 0)
                works = false;
        }

        if(works) hi = (ans = mid) - 1;
        else lo = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
