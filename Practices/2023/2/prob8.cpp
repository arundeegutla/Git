#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    
    int n;

    try {cin >> n;}
    catch(const std::exception& e) {return;}
    
    ll tot = 0;
    vector<int> arr(n);
    for(auto& x : arr){
        cin >> x;
        tot += x;
    } 

    vvi memo(n, vi(tot, -1));
    auto go = [&](int at, int need, auto&& go) -> int {
        if(need == 0) return 1;
        if(at == n || need < 0) return 0;

        auto& ans = memo[at][need];
        if(ans!=-1) return ans;

        bool can = false;
        can |= go(at+1, need, go);
        can |= go(at+1, need-arr[at], go);
        return ans = can;
    };

    int a = tot / 2;
    while(!go(0, a, go)) a--;

    double m = tot / 2.0;
    double area = ceil(((m*m) - ((a - m) * (a - m))) / 2.0);
    cout << (int) area << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    while(cin.good()) solve();
}