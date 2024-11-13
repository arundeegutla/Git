#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times;
    while (n--) {
        int s, e;
        cin >> s >> e;
        times.push_back({s, 1});
        times.push_back({e, -1});
    }
    sort(times.begin(), times.end());
    int ppl = 0;
    int maxx = 0;
    for (auto x : times) {
        ppl += x.second;
        maxx = max(maxx, ppl);
    }

    cout << maxx << "\n";
}