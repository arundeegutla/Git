#include <bits/stdc++.h>
using namespace std;

int memo[40][41][41][2501];

/*
iterate through how many C's are after cur.
if I put A. There is N * C combos of NAC's I can make.
*/

int main() {
    memset(memo, -1, sizeof(memo));

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string NAC = "NAC";
    string buildBack = s;
    function<int(int, int, int, int)> go = [&](int at, int N, int C, int K) -> int {
        if (C < 0 || K < 0) return 0;
        if (at == n) return C == 0 && K == 0;

        auto& ans = memo[at][N][C][K];
        if (ans != -1) return ans;

        // put N.
        if (s[at] == '?' || s[at] == 'N') {
            if (go(at + 1, N + 1, C, K)) {
                buildBack[at] = 'N';
                return ans = 1;
            }
        }

        // put A.
        if (s[at] == '?' || s[at] == 'A') {
            if (go(at + 1, N, C, K - (N * C))) {
                buildBack[at] = 'A';
                return ans = 1;
            }
        }

        // put C.
        if (s[at] == '?' || s[at] == 'C') {
            if (go(at + 1, N, C - 1, K)) {
                buildBack[at] = 'C';
                return ans = 1;
            }
        }

        // put random.
        if (s[at] == '?' || NAC.find(s[at]) == NAC.npos) {
            if (go(at + 1, N, C, K)) {
                if (s[at] == '?')
                    buildBack[at] = 'M';
                else
                    buildBack[at] = s[at];
                return ans = 1;
            }
        }

        return ans = 0;
    };

    // go through all possible Cs.
    for (int i = 0; i <= n; i++) {
        if (go(0, 0, i, k)) {
            cout << buildBack << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}