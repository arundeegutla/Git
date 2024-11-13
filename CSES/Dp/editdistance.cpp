#include <bits/stdc++.h>
using namespace std;
#define int long long

int memo[5001][5001];
signed main() {
    memset(memo, -1, sizeof(memo));
    string a, b;
    cin >> a >> b;

    for (int i = 0; i <= b.size(); i++)
        memo[a.size()][i] = b.size() - i;
    for (int i = 0; i <= a.size(); i++)
        memo[i][b.size()] = a.size() - i;

    for (int at1 = a.size() - 1; at1 >= 0; at1--) {
        for (int at2 = b.size() - 1; at2 >= 0; at2--) {
            int equals = 1e18;
            if (a[at1] == b[at2])
                equals = memo[(at1 + 1)][at2 + 1];
            int replace = memo[at1 + 1][at2 + 1] + 1;
            int remove1 = memo[at1 + 1][at2] + 1;
            int remove2 = memo[at1][at2 + 1] + 1;
            memo[at1][at2] = min({equals, replace, remove1, remove2});
        }
    }

    cout << memo[0][0] << "\n";
}