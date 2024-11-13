#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int b, p;
    cin >> b >> p;
    vector<int> bars(b);
    for (auto& x : bars) cin >> x;
    vector<int> plates(p);
    for (auto& x : plates) cin >> x;

    set<int> pairsOfWeights;
    for (int leftMask = 1; leftMask < (1 << p) - 1; leftMask++) {
        int w = 0;
        for (int i = 0; i < p; i++) {
            if ((leftMask & (1 << i)) != 0) {
                w += plates[i];
            }
        }

        vector<int> rightMasks;
        function<void(int, int)> getMasks;
        getMasks = [&](int at, int mask) -> void {
            if (at == p) {
                rightMasks.push_back(mask);
                return;
            }
            getMasks(at + 1, mask);
            if ((leftMask & (1 << at)) == 0)
                getMasks(at + 1, mask | (1 << at));
        };
        getMasks(0, 0);

        for (auto& mask : rightMasks) {
            int rw = 0;
            for (int i = 0; i < p; i++) {
                if ((mask & (1 << i)) != 0) {
                    rw += plates[i];
                }
            }
            if (w == rw) {
                pairsOfWeights.insert(w + rw);
            }
        }
    }

    set<int> weights;
    for (auto bar : bars) {
        weights.insert(bar);
        for (auto pair : pairsOfWeights) {
            weights.insert(bar + pair);
        }
    }

    for (auto x : weights) {
        cout << x << "\n";
    }
}