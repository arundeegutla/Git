#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

void solve() {
    int B, n;
    cin >> B >> n;

    using info = pair<int, pair<int, int>>;
    vector<vector<info>> adj;

    unordered_map<string, int> id;
    for (int i = 0; i < n; i++) {
        string dish, base, ing;
        int c, p;
        cin >> dish >> base >> ing >> c >> p;

        if (!id.count(dish)) {
            id[dish] = id.size();
            adj.push_back(vector<info>());
        }
        if (!id.count(base)) {
            id[base] = id.size();
            adj.push_back(vector<info>());
        }
        adj[id[dish]].push_back({id[base], {c, p}});
    }

    using info2 = pair<int, int>;
    auto getBest = [&](info2 a, info2 b) -> bool {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    };

    vector<info2> memo(id.size(), {-1, -1});
    function<info2(int)> go = [&](int at) -> info2 {
        if (adj[at].size() == 0) return memo[at] = {0, 0};
        auto& ans = memo[at];
        if (ans.first != -1) {
            return ans;
        }
        info2 best = {1e18, 0};
        for (auto [e, i] : adj[at]) {
            auto next = go(e);
            next.first += i.first;
            next.second += i.second;
            if (!getBest(best, next)) {
                best = next;
            }
        }
        assert(best.first != 1e18);
        return ans = best;
    };

    for (int i = 0; i < id.size(); i++) {
        auto here = go(i);
    }

    vector<vector<info2>> memo2(id.size(), vector<info2>(B + 1, {-1, -1}));
    function<info2(int, int)> go2 = [&](int at, int curCost) -> info2 {
        if (curCost > B) return {1e18, -1e18};
        if (at == id.size()) return {0, 0};
        auto& ans = memo2[at][curCost];
        if (ans.first != -1) return ans;

        auto leave = go2(at + 1, curCost);
        auto take = go2(at + 1, curCost + memo[at].first);
        take.first += memo[at].first;
        take.second += memo[at].second;

        int best = max(leave.second, take.second);
        if (take.second == best && leave.second == best) {
            return ans = {min(leave.first, take.first), best};
        }
        if (take.second == best) {
            return ans = take;
        }
        return ans = leave;
    };

    auto best = go2(0, 0);
    cout << best.second << "\n";
    cout << best.first << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}