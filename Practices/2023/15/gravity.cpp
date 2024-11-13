#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (auto& x : grid) cin >> x;

    auto go = [&](int col) -> void {
        int dropTo = r - 1;
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][col] == 'o') {
                grid[i][col] = '.';
                grid[dropTo][col] = 'o';
                dropTo--;
            }
            if (grid[i][col] == '#') {
                dropTo = i - 1;
            }
        }
    };

    for (int i = 0; i < c; i++) {
        go(i);
    }

    for (auto s : grid) {
        cout << s << "\n";
    }
}