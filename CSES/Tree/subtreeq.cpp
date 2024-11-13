#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
    int n;
    vector<T> t;
    BIT(int n) : n(n++), t(n) {}
    void update(int i, T v) {
        for (i++; i <= n; i += i & -i) t[i] += v;
    }
    T query(int i) {
        T ans = 0;
        for (i++; i > 0; i -= i & -i) ans += t[i];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> value(n);
    for (auto& x : value) cin >> x;

    vector<vector<int>> tree(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> start(n), end(n);
    int timer = 0;
    function<void(int, int)> euler_tour = [&](int at, int prev) {
        start[at] = ++timer;
        for (auto e : tree[at])
            if (e != prev)
                euler_tour(e, at);
        end[at] = timer;
    };
    euler_tour(0, -1);

    BIT<long long> cumFreq(n + 10);
    for (int i = 0; i < n; i++)
        cumFreq.update(start[i], value[i]);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            auto there = cumFreq.query(start[s], start[s]);
            cumFreq.update(start[s], -there);
            cumFreq.update(start[s], x);
        } else {
            int s;
            cin >> s;
            s--;
            cout << cumFreq.query(start[s], end[s]) << "\n";
        }
    }
}