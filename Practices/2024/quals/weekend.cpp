#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll l, h;
    cin >> l >> h;
    ll c, n, e;
    cin >> c >> n >> e;
    ll numC, numN, numE;
    cin >> numC >> numN >> numE;

    // if i buy one, what is prob that it will fit in the budget.
    vvvi memo(numC + 1, vvi(numN + 1, vi(numE + 1, -1)));
    function<double(int, int, int)> go = [&](int haveC, int haveN, int haveE) -> double {
        if (haveC < 0 || haveN < 0 || haveE < 0) return 0;
        if (haveC == 0 && haveN == 0 && haveE == 0) return 0;

        auto& ans = memo[haveC][haveN][haveE];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        int totHere = haveC + haveN + haveE;
        ll curCost = ((numC - haveC) * c) + ((numN - haveN) * n) + ((numE - haveE) * e);
        if (curCost >= l && curCost <= h) return 1;

        double prob = 0;
        prob += (haveC / (totHere * 1.0)) * go(haveC - 1, haveN, haveE);
        prob += (haveN / (totHere * 1.0)) * go(haveC, haveN - 1, haveE);
        prob += (haveE / (totHere * 1.0)) * go(haveC, haveN, haveE - 1);

        // cout << prob << "\n";
        return ans = prob;
    };

    cout << fixed << setprecision(10) << go(numC, numN, numE) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}