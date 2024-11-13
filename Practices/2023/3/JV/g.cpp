#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    reverse(all(s));

    string ans;
    ans.push_back(s.back());
    s.pop_back();
    while(s.size()){
        if(s.back() < ans.back()) break;
        ans.push_back(s.back());
        s.pop_back();
    }


    if(!s.size()){
        cout << ans << "\n";
        return;
    }

    ans.push_back(s.back());
    s.pop_back();

    while(s.size()){
        if(s.back() > ans.back()) {
            ans.resize(n, ans.back());
            break;
        } else {
            ans.push_back(s.back());
            s.pop_back();
        }
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}