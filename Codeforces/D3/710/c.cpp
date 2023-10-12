#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string a, b;
    cin >> a >> b;

    vvi memo(a.size(), vi(b.size(), -1));
    auto go = [&](int atA, int atB, auto&& go) -> int {
        if(atA >= a.size() || atB >= b.size()) return 0;
        auto& ans = memo[atA][atB];
        if(ans != -1) return ans;

        int maxx = go(atA, atB+1, go);
        maxx = max(maxx, go(atA+1, atB, go));
        int longest = 0;
        for(int i = atA, j = atB; i < a.size() && j < b.size(); i++, j++){
            if(a[i] != b[j]) break;
            longest++;
        }
        maxx = max(maxx, longest);
        return ans = maxx;
    };


    int longest = go(0, 0, go);

    cout << (a.size() - longest) + (b.size() - longest) << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}