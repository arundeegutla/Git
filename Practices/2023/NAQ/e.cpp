#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pref(n);
    for (auto& [s, e] : pref) {
        cin >> s >> e;
        s--, e--;
    }

    int count = 0;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        // start.
        bool found = false;
        if (used[i]) continue;
        for (int j = pref[i].first; j <= pref[i].second && !found; j++) {
            // second person.
            if (used[j]) continue;
            for (int k = pref[i].first; k <= pref[i].second && !found; k++) {
                // third person.
                if (used[k]) continue;
                if (i == k || i == j || j == k) continue;
                if (used[i] || used[j] || used[k]) continue;

                // i inbounds for j?
                if (!(pref[j].first <= i && i <= pref[j].second)) continue;
                // i inbounds for k?
                if (!(pref[k].first <= i && i <= pref[k].second)) continue;

                // j inbounds for k?
                if (!(pref[k].first <= j && j <= pref[k].second)) continue;

                // k inbounds for j?
                if (!(pref[j].first <= k && k <= pref[j].second)) continue;

                found = true;
                used[i] = used[j] = used[k] = true;
                count++;
            }
        }
    }
    cout << count << "\n";
}
