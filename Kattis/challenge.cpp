#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int rounds = n + m - 1;
    vector<double> winning(rounds);
    for (auto& x : winning) cin >> x;

    vector<vector<double>> memo(rounds, vector<double>(m + 1, -1));
    function<double(int, int)> go = [&](int at, int other) -> double {
        if (other == 0) return 1;
        int otherLost = m - other;
        int myLost = n - (at - otherLost);
        if (myLost <= 0) return 0;
        if (at == rounds) return 0;

        auto& ans = memo[at][other];
        if (ans != -1) {
            return ans;
        }
        // win this round.
        double win = winning[at] * go(at + 1, other - 1);
        double dontWin = (1 - winning[at]) * go(at + 1, other);
        return ans = win + dontWin;
    };

    cout << fixed << setprecision(10) << go(0, m) << "\n";
}