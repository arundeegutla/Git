#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int m = nextInt();
    set<pair<int, int>> segs;
    while(m--) 
        segs.insert({nextInt(), nextInt()});
    vector<int> update(nextInt());
    for(auto& x : update) x = nextInt();
    
    auto go = [&](int mid) -> bool {
        vector<int> changed(n+1);
        for(int i = 0; i < mid; i++)
            changed[update[i]] = 1;
        for(int i = 1; i <= n; i++)
            changed[i] += changed[i-1];

        for(auto p : segs){
            int need = (p.second - p.first + 1) / 2;
            int actual = changed[p.second] - changed[p.first-1];
            if(actual > need)
                return true;
        }
        return false;
    };

    int lo = 1;
    int high = update.size()+1;
    while(lo < high){
        int mid = (lo+high)/2;
        if(go(mid)) high = mid;
        else lo = mid+1;
    }

    cout << (high == update.size()+1? -1 : high) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}