#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> seen(7, vector<int>(7));
    auto go = [&](int r, int c, auto&& go) -> int {
        if (r >= 7 || r < 0 || c >= 7 || c < 0 || seen[r][c]) return 0;
        if (r == 6 && c == 0) return 1;

        int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        seen[r][c] = true;
        int ways = 0;
        for (auto& d : D) {
            int nR = d[0] + r;
            int nC = d[1] + c;
            ways += go(nR, nC, go);
        }
        seen[r][c] = false;
        return ways;
    };

    cout << go(0, 0, go) << "\n";
}