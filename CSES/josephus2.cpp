#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int n, k;
    cin >> n >> k;
    BIT<ll> tree(n + 10);
    for (int i = 1; i <= n; i++) tree.update(i, 1);

    vector<int> order;
    int cur = (k % n) + 1;
    while (true) {
        order.push_back(cur);

        if (order.size() == n) break;

        int indx = tree.query(0, cur) - 1;
        tree.update(cur, -1);

        int total = n - order.size();
        int nextIndx = (indx + (k % total)) % total;

        int lo = 1;
        int hi = n;
        int num = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int indx2 = tree.query(0, mid) - 1;
            if (indx2 >= nextIndx) {
                hi = (num = mid) - 1;
            } else {
                lo = mid + 1;
            }
        }

        assert(num != -1);
        cur = num;
    }

    for (auto x : order) {
        cout << x << " ";
    }
    cout << "\n";
}