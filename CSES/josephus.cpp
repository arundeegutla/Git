#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> hset;
    for (int i = 1; i <= n; i++) {
        hset.insert(i);
    }

    bool skippedLast = false;
    int lastRemoved = -1;
    while (hset.size()) {
        auto itr = hset.upper_bound(lastRemoved);
        bool flag = false;
        if (hset.size() != 1 && itr != hset.end() && !skippedLast) {
            itr++;
            flag = true;
        }
        skippedLast = false;
        if (itr == hset.end()) {
            if (flag) skippedLast = true;
            lastRemoved = -1;
            continue;
        }
        cout << (*itr) << " ";
        lastRemoved = (*itr);
        hset.erase(itr);
    }
    cout << "\n";
}