#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, pair<int, int>>> speedUps(n);
    for (auto& [x, p] : speedUps) {
        cin >> x;
        auto& [m, d] = p;
        cin >> m >> d;
    }

    sort(speedUps.begin(), speedUps.end());

    vector<vector<double>> memo(n, vector<double>(n + 1, -1));
    function<double(int, int)> go = [&](int at, int last) -> double {
        if (at == n) {
            if (last == -1) return l;

            auto [start, p] = speedUps[last];
            auto [m, d] = p;
            if (start + (m * d) <= l) return d + l - (start + (m * d));
            return (l - start) / (m * 1.0);
        }

        auto& ans = memo[at][last + 1];
        if (ans != -1) return ans;

        double minn = 1e18;
        //                  m                          *            d      +              start               <= x

        if (last == -1) {
            minn = min(minn, speedUps[at].first + go(at + 1, at));
        } else {
            // can take.
            auto [start, p] = speedUps[last];
            auto [m, d] = p;
            if (start + (m * d) > l)

                int stopped = (speedUps[last].second.first * speedUps[last].second.second) + speedUps[last].first;
            double time = (speedUps[at].first - stopped) + (last == -1 ? 0 : speedUps[last].second.second);
            // cout << at << " " << time << "\n";
            minn = min(minn, go(at + 1, at) + time);
        }

        minn = min(minn, go(at + 1, last));

        return ans = minn;
    };

    cout << fixed << setprecision(10) << go(0, -1) << "\n";
}