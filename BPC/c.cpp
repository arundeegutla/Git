#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stk(n);
    for (auto& x : stk) cin >> x;

    vector<int> psum(n + 1);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + stk[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int sum = psum[i + 1];

        int left = i + 1;
        int right = n - 1;
        int ans2 = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            int sumHere = psum[mid + 1] - psum[i + 1];
            if (sumHere == sum) {
                ans2 = mid;
                break;
            }
            if (sumHere < sum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (ans2 == -1) continue;
        left = ans2 + 1;
        right = n - 1;
        int ans3 = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int sumHere = psum[mid + 1] - psum[ans2 + 1];
            if (sumHere == sum) {
                ans3 = mid;
                break;
            }
            if (sumHere < sum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (ans3 != -1) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}