#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}


void solve() {
    string s = next();
    reverse(s.begin(), s.end());

    vector<int> translate = {1, 10, 100, 1000, 10000};

    vvvi memo(s.size(), vvi(2, vi(6, -1)));

    auto go = [&](int at, int changed, int maxx, auto && go) -> ll {
        if(at == s.size()) return 0;
        ll& ans = memo[at][changed][maxx+1];
        if(ans != -1) return ans;
        int val = s[at]-'A';
        ll change = -(ll)1e10;
        if(!changed)
            for(int i = 0; i < 5; i++)
                change = max(change, go(at+1, true, max(maxx, i), go) + ((i<maxx?-1:1) * translate[i]));
        ll dontChange = go(at+1, changed, max(maxx, val), go) + ((val<maxx?-1:1) * translate[val]);
        return ans = max(change, dontChange);
    };

    cout << go(0, 0, -1, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}