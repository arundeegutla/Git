#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    unordered_map<int, vector<int>> ind;
    for (int i = 0; i < n; i++)
        ind[arr[i]].push_back(i);

    auto getCount = [&](int val, int l, int r) -> int {
        return upper_bound(ind[val].begin(), ind[val].end(), r) - lower_bound(ind[val].begin(), ind[val].end(), l);
    };

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;

        bool done = false;
        for (int i = 0; i < 50; i++) {
            int randInd = (rand() % len) + l;
            int count = getCount(arr[randInd], l, r);
            if (count * 2 > len) {
                cout << arr[randInd] << "\n";
                done = true;
                break;
            }
        }
        if (!done) {
            cout << 0 << "\n";
        }
    }
}