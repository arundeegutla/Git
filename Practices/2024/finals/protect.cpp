#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string f, l;
    cin >> f >> l;
    int MOD = 1e9 + 7;

    using vi = vector<ll>;
    using vvi = vector<vi>;
    using vvvi = vector<vvi>;
    vvvi memo(n, vvi(2, vi(2, -1)));

    function<ll(int, int, int)> go = [&](int at, int usedF, int usedL) -> ll {
        if(at > n) return 0;
        if(at == n) {
            return max(usedF, usedL);
        }

        cout << at << " " << usedF << " " << usedL << "\n";
        auto& ans = memo[at][usedF][usedL];
        // if(ans != -1) return ans;
        cout << "here\n";
        // put f.
        ll count = 0;
        if(!usedF)
            count += go(at + f.size(), 1, usedL);
        if(!usedL)
            count += go(at + l.size(), usedF, 1);

        count %= MOD;
        count += (go(at + 1, usedF, usedL) * 26) % MOD;
        count %= MOD;

        return ans = count;

    };  


    cout << go(0, 0, 0) << "\n"; 

}