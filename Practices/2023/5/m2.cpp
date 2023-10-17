#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s;
    cin >> s;


    vvi memo(s.size(), vi(2, -1));
    auto go = [&](int at, bool next, auto&& go) -> ll {
        if(at == -1) return next ? 0 : 1e10;

        bool ogEqual = s[at] == s[s.size() - at - 1];
        auto& ans = memo[at][next];

        if(ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        
        // cur dont match
        if(!ogEqual) {
            if(!next) {
                ll changeNext = go(at - 1, true, go) + 1;
                return ans = changeNext;
            }
            ll changeNext = go(at - 1, true, go) + (((s.size() % 2 != 0 && at+1 == s.size() / 2) || (at+1 == s.size() - at - 1)) ? 1 : 2);
            ll dontChange = go(at - 1, false, go);
            return ans = min(changeNext, dontChange);
        } else {
            if(!next) {
                ll matchBoth = go(at - 1, true, go) + (((s.size() % 2 != 0 && at+1 == s.size() / 2) || (at+1 == s.size() - at - 1)) ? 1 : 2);
                ll matchNext = go(at-1, false, go) + 1;
                return ans = min(matchBoth, matchNext);
            }
        }
        return ans = go(at-1, true, go);
    };


    cout << go(s.size()/2 - 1, true, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}