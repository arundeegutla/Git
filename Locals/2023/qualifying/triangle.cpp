#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int totPoints = 3 * n;
    vector<pair<double, double>> points(3 * n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }

    auto getArea = [&](vector<pair<double, double>>& triangle) -> double {
        auto& p1 = triangle[0];
        auto& p2 = triangle[1];
        auto& p3 = triangle[2];
        return 0.5 * abs(((p1.first * (p2.second - p3.second)) + (p2.first * (p3.second - p1.second)) + (p3.first * (p1.second - p2.second))));
    };

    double close = 1e18;
    auto go = [&](int at, int taken, double maxx, double minn, auto&& go) -> void {
        if (at == n) {
            close = min(close, maxx - minn);
            return;
        }

        vector<int> availble;
        for (int i = 0; i < totPoints; i++)
            if ((taken & (1 << i)) == 0)
                availble.push_back(i);

        for (int mask = 0; mask < (1 << availble.size()); mask++) {
            if (bitset<16>(mask).count() != 3) continue;
            int here = 0;
            for (int i = 0; i < availble.size(); i++)
                if ((mask & (1 << i)) != 0)
                    here |= (1 << availble[i]);

            vector<pair<double, double>> triangle;
            for (int i = 0; i < totPoints; i++)
                if ((here & (1 << i)) != 0)
                    triangle.push_back(points[i]);

            double area = getArea(triangle);

            double nextMinn = min(minn, area);
            double nextMaxx = max(maxx, area);
            if (at > 0 && close < nextMaxx - nextMinn) {
                continue;
            }

            go(at + 1, taken | here, nextMaxx, nextMinn, go);
        }
    };

    vector<int> trash;
    go(0, 0, INT_MIN, INT_MAX, go);

    cout << fixed << setprecision(1) << close << "\n";
}