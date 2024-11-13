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
    int n, t;
    cin >> n >> t;
    BIT<int> tree(n + 10);

    while (t--) {
        char c;
        cin >> c;
        if (c == 'A') {
            int l, r;
            cin >> l >> r;
            int occup = tree.query(l, r);
            cout << (r - l + 1) - occup << "\n";
        } else {
            int x;
            cin >> x;
            tree.update(x, 1);
        }
    }
}