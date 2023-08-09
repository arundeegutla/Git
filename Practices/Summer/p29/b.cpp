#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}


struct BIT {
    int sz;
    vector<ll> freq;
    BIT(int n) {
        sz = 1;
        while (sz <= n) sz <<= 1;
        freq.assign(sz, 0);
    }
    ll sum(int idx) {
        ll res = 0;
        while (idx) {
            res += freq[idx];
            idx -= (idx&(-idx));
        }
        return res;
    }
    ll sum(int low, int high) {
        return sum(high) - sum(low-1);
    }
    void add(int idx, ll val){
        while (idx < sz) {
            freq[idx] += val;
            idx += (idx&(-idx));
        }
    }
};


void solve() {
    int n = nextInt();
    int m = nextInt();

    vector<pair<int, int>> ranges(m);
    for(auto& x : ranges){
        x.first = nextInt();
        x.second = nextInt();
    }
    BIT tree(n+10);

    auto mySort = [](pair<int, int>& a, pair<int, int>& b) -> bool {
        return a.second - a.first < b.second - b.first;
    };
    sort(ranges.begin(), ranges.end(), mySort);

    

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}