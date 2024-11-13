#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int MAXX = 500;
double dp[MAXX][MAXX][MAXX];

int main() {
    for (auto& two : dp)
        for (auto& one : two)
            fill(begin(one), end(one), -1.0);

    int n;
    cin >> n;
    int ones = 0;
    int twos = 0;
    int threes = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ones += x == 1;
        twos += x == 2;
        threes += x == 3;
    }

    auto go = [&](int a, int b, int c, auto&& go) -> double {
        if (a < 0 || b < 0 || c < 0) return 0;
        if (a == 0 && b == 0 && c == 0) return 0;

        auto& ans = dp[a][b][c];
        if (ans != -1.0) {
            // cout << "memo!\n";
            return ans;
        }

        double all = a + b + c;
        double expected = n / all;
        expected += (go(a - 1, b, c, go) * a) / all;
        expected += (go(a + 1, b - 1, c, go) * b) / all;
        expected += (go(a, b + 1, c - 1, go) * c) / all;

        return ans = expected;
    };

    cout << fixed << setprecision(10) << go(ones, twos, threes, go) << "\n";
}