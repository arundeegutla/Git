#include <bits/stdc++.h>
using namespace std;
#define long long long

int main() {
    long oo = -((long)1e18);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> potions(n);
    for(auto& x : potions)
        cin >> x;
    
    vector<vector<long>> memo(n, vector<long> (n+1, oo));
    auto go = [&](int at, int need, auto && go) -> long {
        if(need == 0) return 0;
        if(at == -1) return (int)-1e9;
        long& ans = memo[at][need];
        if(ans != oo) return ans;
        long sum = go(at-1, need-1, go);
        long dont = go(at-1, need, go);
        if(sum < 0 || sum + potions[at] < 0) sum = (int)-1e9;
        else sum += potions[at];
        return ans = max(sum, dont);
    };

    int lo = 0;
    int high = n;
    int ans = 0;
    while (lo <= high) {
        int mid = (lo+high)/2;
        long thisAns = go(n-1, mid, go);
        if(thisAns >= 0) {
            ans = mid;
            lo = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans << "\n";
}