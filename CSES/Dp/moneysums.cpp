#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    vector<vector<int>> memo(n, vector<int>(1e5 + 1, -1));
    function<int(int, int)> go = [&](int at, int need) -> int {
        if (need == 0) return 1;
        if (at >= arr.size() || need < 0) return 0;
        auto& ans = memo[at][need];
        if (ans != -1) return ans;
        return ans = max({go(at + 1, need - arr[at]), go(at + 1, need)});
    };

    vector<int> ans;
    for (int i = 1; i <= 1e5; i++) {
        if (go(0, i) == 1) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";

    cout << "\n";
}