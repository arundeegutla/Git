#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    int n = s.size();
    vector<vector<int>> psums(26, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        psums[s[i] - 'a'][i + 1]++;
    }

    for (auto& arr : psums) {
        for (int i = 1; i <= n; i++) {
            arr[i] += arr[i - 1];
        }
    }

    auto can = [&](int start, int end) -> bool {
        int maxx = 0;
        for (int i = 0; i < 26; i++) {
            maxx = max(maxx, psums[i][end + 1] - psums[i][start]);
        }

        int tot = end - start + 1;

        return tot - maxx <= m;
    };

    auto get = [&](int start, int end) -> int {
        int maxx = 0;
        for (int i = 0; i < 26; i++) {
            maxx = max(maxx, psums[i][end + 1] - psums[i][start]);
        }

        return maxx;
    };

    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int lo = i;
        int hi = n - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (can(i, mid)) {
                lo = (ans = mid) + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (ans != -1) {
            maxx = max(maxx, get(i, ans));
            // cout << get(i, ans) << " " << i << "\n";
        }
    }

    cout << maxx << "\n";
}