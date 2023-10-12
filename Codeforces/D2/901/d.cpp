#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    
    int n;
    cin >> n;
    vector<int> freq(5010);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 5005) continue;
        freq[x]++;
    } 

    auto psum = freq;
    psum[0] = freq[0];
    for(int i = 1; i < freq.size(); i++)
        psum[i] = psum[i-1] + freq[i];

    auto mex = [&]() -> int {
        for(int i = 0; i < 5002; i++)
            if(!freq[i])
                return i;
        return 5005;
    };

    int curMex = mex();
    vvi memo(curMex+10, vi(curMex+10, -1));
    auto go = [&](int at, int mex, auto&& go) -> ll {

        if(at == -1)
            return mex == 0 ? 0 : 1e10;


        auto& ans = memo[at][mex];

        if(ans!=-1){
            // cout << "memo!\n";
            return ans;
        } 

        // make this mex.
        ll m = (mex * (freq[at]-1)) + at;
        m += go(at-1, at, go);

        // dont make this mex.
        ll no = go(at-1, mex, go);

        return ans = min(m, no);
    };

    
    cout << go(curMex-1, curMex, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}