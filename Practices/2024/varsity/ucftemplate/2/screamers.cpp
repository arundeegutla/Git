#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int MAXD = 51, MAXR = 2501;

int D, R;

// Amount of ways to get valid integer point w/ dim 'd' and radius 'r'
ll ways[MAXD][MAXR];

// dp[i][j] = sum of integer coordinates of all points in ways[i][j]
ll dp[MAXD][MAXR];

pair<ll, ll> go(int d, int r) {
    // Already seen
    if (ways[d][r] != -1)
        return make_pair(ways[d][r], dp[d][r]);

    ll cnt = 0; // Ways
    ll res = 0; // Sum

    for (int x = 0; x*x <= r; x++) {
        // a -> num ways | b -> sum of coords
        ll a, b; tie(a, b) = go(d-1, r-x*x);

        // Count x and -x
        if (x > 0) {
            a *= 2;
            b *= 2;
        }

        // Add to number of ways
        cnt += a;
        cnt %= MOD;
        
        // dp[d][r] += dp[d-1][r-x*x] + ways[d-1][r-x*x] * x
        // Take sum of all coordinates, then add the number of points in
        // that sum and multiply it by 'x'. That will give the new sum.
        res += a*x + b;
        res %= MOD;
    }

    return make_pair(ways[d][r] = cnt, dp[d][r] = res);
}

ll solve() {
    // -1 means unvisited
    memset(ways, -1, sizeof(ways));
    memset(dp, 0, sizeof(dp));

    // Radius squared
    int R2 = R*R;

    // Base cases
    ways[0][0] = 1;
    for (int i = 1; i < MAXR; i++)
        ways[0][i] = 0;
    
    // Sum all sums inside the sphere in dimension 'D'
    ll res = 0;
    for (int i = 0; i <= R2; i++)
        res += go(D, i).second;

    // Answer
    return (res % MOD);
}

int main() {
    cin >> D >> R;
    cout << solve() << endl;
}