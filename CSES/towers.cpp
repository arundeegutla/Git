#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    map<int, int> hmap;
    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        auto itr = hmap.upper_bound(curr);
        if (itr == hmap.end()) {
            hmap[curr]++;
        } else {
            int num = (*itr).first;
            hmap[num]--;
            if (hmap[num] == 0) hmap.erase(num);
            hmap[curr]++;
        }
    }

    int towers = 0;
    for (auto& [_, v] : hmap) towers += v;

    cout << towers << "\n";
}