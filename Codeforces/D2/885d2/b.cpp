#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt(), k = nextInt();

    vector<set<int>> color(k);
    for(int i = 0; i < n; i++)
        color[nextInt() - 1].insert(i);

    auto can = [&](int steps) -> bool {
        for(int c = 0; c < k; c++){
            int at = -1;
            bool colored = false;
            while(at < n){
                auto itr = color[c].upper_bound(at);
                if(n - at - 1 <= steps){
                    at = n;
                    break;
                }
                if(itr == color[c].end() || (*(itr)-at-1) > steps){
                    if(colored) break;
                    colored = true;
                    at += steps+1;
                } else {
                    at = *(itr);
                }
            }
            if(at>=n) return true;
        }
        return false;
    };

    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(can(mid)){
            hi = (ans = mid) - 1;
        } else
            lo = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}