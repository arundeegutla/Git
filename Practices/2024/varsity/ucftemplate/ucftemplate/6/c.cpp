#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

ll MOD = 1e9;

vvi multiply(vvi& A, vvi& B) {
    int n = A.size();
    vvi C(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

vvi identity(int n) {
    vvi m(n, vi(n));
    for (int i = 0; i < n; i++)
        m[i][i] = 1;
    return m;
}

vvi matrixExpo(vvi base, ll exp) {
    int n = base.size();
    if (exp == 0) return identity(n);
    if (exp % 2 == 0) {
        vvi sqrt = matrixExpo(base, exp / 2);
        return multiply(sqrt, sqrt);
    }
    vvi tmp = matrixExpo(base, exp - 1);
    return multiply(tmp, base);
}

void solve() {
    int N, M;
    cin >> N >> M;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}
