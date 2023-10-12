#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for(auto& x : arr) cin >> x;

    vi memo(1<<n, -1);

    auto go = [&](int mask, auto&& go) -> double {
        int numPpl = bitset<30>(mask).count();
        if(numPpl == 2) return 0;

        auto& ans = memo[mask];
        if(ans!=-1) return ans;

        double allWhites = 1;
        double allBlacks = 1;

        for(int i = 0; i < n; i++){
            if(!(mask & (1<<i))) continue;
            allWhites *= arr[i];
            allBlacks *= 1 - arr[i];
        }

        double tot = 1;
        double denom = 0;


        for(int i = 0; i < n; i++){
            if(!(mask & (1<<i))) continue;

            // make this guy to black
            double everyOneElseWhites = (allWhites / arr[i]) * (1 - arr[i]);
            // make this guy to white
            double everyOneElseBlacks = (allBlacks / (1 - arr[i])) * arr[i];

            double x = everyOneElseBlacks + everyOneElseWhites;
            denom += x;
            
            double next = go(mask ^ (1<<i), go);
            tot += next * x;
        }

        return ans = tot / denom;
    };

    cout << fixed << setprecision(10) << go((1<<n)-1, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}