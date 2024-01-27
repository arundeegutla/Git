#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt()-1;

    vector<set<int>> inds(n, set<int>());
    for(int i = 0; i < n; i++){
        while(i+1<n&&arr[i+1]==arr[i]) i++;
        inds[arr[i]].insert(i);
    }

    vector<int> memo(n, -1);
    auto go = [&](int at, auto && go) -> int {
        if(at == n) return 0;
        int& ans = memo[at];
        if(ans!=-1)return ans;
        int maxx = go(at+1, go);
        auto itr = inds[arr[at]].upper_bound(at);
        while (itr != inds[arr[at]].end()) {
            maxx = max(maxx, go((*itr)+1, go) + ((*itr)-at+1));
            itr++;
        }
        return ans = maxx;
    };

    cout << go(0, go) << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}
