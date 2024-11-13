#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Info {
    int len, count;
};

signed main() {
    int n;
    cin >> n;

    vector<int> labels(n);
    for (auto& x : labels) cin >> x;

    vector<vector<int>> tree(n);

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--;
        tree[parent].push_back(i);
    }

    set<int> ordered(labels.begin(), labels.end());
    unordered_map<int, int> cmap;
    for (auto x : ordered)
        cmap[x] = cmap.size();
    for (auto& x : labels)
        x = cmap[x];

    int MOD = 11092019;
    unordered_map<int, unordered_map<int, Info>> memo;

    function<Info(int, int)> go;

    go = [&](int at, int anscestor) -> Info {
        if (memo.find(at) != memo.end()) {
            if (memo[at].find(anscestor) != memo[at].end()) {
                // cout << "memo!\n";
                return memo[at][anscestor];
            }
        }

        Info best = {anscestor <= labels[at], anscestor <= labels[at]};

        // leave this one.
        for (auto e : tree[at]) {
            auto next = go(e, anscestor);
            if (next.len > best.len) {
                best = next;
            } else if (next.len == best.len) {
                best.count += next.count;
                best.count %= MOD;
            }
        }

        // take this one.
        if (anscestor == -1) {
            for (auto e : tree[at]) {
                auto next = go(e, labels[at]);
                next.len++;
                if (next.len > best.len) {
                    best = next;
                } else if (next.len == best.len) {
                    best.count += next.count;
                    best.count %= MOD;
                }
            }
        } else if (anscestor <= labels[at]) {
            for (auto e : tree[at]) {
                auto next = go(e, labels[at]);
                next.len++;
                if (next.len > best.len) {
                    best = next;
                } else if (next.len == best.len) {
                    best.count += next.count;
                    best.count %= MOD;
                }
            }
        }

        // cout << at << " " << anscestor << ": " << best.len << " " << best.count << "\n";
        return memo[at][anscestor] = best;
    };

    auto ans = go(0, -1);

    cout << ans.len << " " << ans.count << "\n";
}