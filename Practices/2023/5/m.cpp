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
    int half = s.size() / 2;

    vvi memo(s.size(), vi(2, -1));
    auto go = [&](int at, bool changed, auto&& go) -> ll {
        if(at == half) return 0;

        bool matched = s[at] == s[s.size() - at - 1];
        if(changed) matched = !matched;
        
        auto& ans = memo[at][changed];
        if(ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        if(!matched) {
            ll changeBoth = go(at+1, true, go) + 1;
            ll changeOne = go(at+1, false, go) + 2;
            return ans = min(changeBoth, changeOne);
        }
        
        if(changed) {
            ll changeAgain = go(at+1, true, go) + 1;
            ll dontChange = go(at+1, false, go);
            return ans = min(changeAgain, dontChange);
        }

        return ans = go(at+1, false, go);
    };


    cout << go(0, false, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}