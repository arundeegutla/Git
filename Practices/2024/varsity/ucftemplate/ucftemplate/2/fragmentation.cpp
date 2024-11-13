#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using S = array<pii, 2>;

struct ST {
    vector<map<int, int>> v;

    ST(int n) : v(4 * n) {}

    void update(int ti, const map<int, int>& factors, int bl, int br, int bi) {
        if (bl == br) {
            v[bi] = factors;
            return;
        }

        int bm = (bl + br) / 2;
        if (ti <= bm)
            update(ti, factors, bl, bm, bi * 2);
        else
            update(ti, factors, bm + 1, br, bi * 2 + 1);

        if (v[bi * 2].size() <= v[bi * 2 + 1].size()) {
            v[bi] = v[bi * 2 + 1];
            for (auto [p, ct] : v[bi * 2])
                v[bi][p] += ct;
            return;
        }
        // >
        v[bi] = v[bi * 2];
        for (auto [p, ct] : v[bi * 2 + 1])
            v[bi][p] += ct;
    }

    map<int, int> query(int tl, int tr, int bl, int br, int bi) {
        if (tl > tr)
            return {};
        if (tl == bl && tr == br)
            return v[bi];

        int bm = (bl + br) / 2;
        auto l = query(tl, min(tr, bm), bl, bm, bi * 2);
        auto r = query(max(bm + 1, tl), tr, bm + 1, br, bi * 2 + 1);
        if (l.size() <= r.size()) {
            for (auto [p, ct] : l)
                r[p] += ct;
            return r;
        }
        // l > r
        for (auto [p, ct] : r)
            l[p] += ct;
        return l;
    }
};

int main() {
    vector<int> arePrime(1e6 + 1, 1);
    arePrime[1] = 0;
    for (ll i = 2; i * i <= (ll)1e6; i++) {
        if (!arePrime[i])
            continue;
        for (ll j = i * i; j * j <= (ll)1e6; j += i)
            arePrime[j] = 0;
    }

    vector<int> primes;
    for (int i = 2; i <= 1e6; i++) {
        if (arePrime[i])
            primes.push_back(i);
    }

    auto factorize = [&](int k) {
        map<int, int> factors;
        for (auto p : primes) {
            if (k == 1)
                break;
            int ct = 0;
            while (k % p == 0) {
                k /= p;
                ct++;
            }
            factors[p] = ct;
        }
        return factors;
    };

    int n;
    cin >> n;
    ST st(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        auto factors = factorize(k);
        st.update(i, factors, 0, n - 1, 1);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        auto actual = st.query(l - 1, r - 1, 0, n - 1, 1);
        auto factors = factorize(k);

        bool valid = true;
        for (auto [p, ct] : factors) {
            if (!actual.count(p) || actual[p] < ct) {
                cout << "No\n";
                valid = false;
                break;
            }
        }
        if (valid) cout << "Yes\n";
    }

    return 0;
}