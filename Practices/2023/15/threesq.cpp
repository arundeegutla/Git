#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rect {
    int w, h;
};

int main() {
    vector<pair<int, pair<int, int>>> rectangles(3);
    int cid = 0;
    for (auto& [id, p] : rectangles) {
        id = cid++;
        auto& [w, h] = p;
        cin >> w >> h;
    }

    for (int i = 0; i < 3; i++) {
        auto [id, p] = rectangles[i];
        auto [w, h] = p;
        rectangles.push_back({id, {h, w}});
    }

    vector<int> perm = {0, 1, 2, 3, 4, 5};

    do {
        unordered_set<int> ids;
        vector<Rect> rects;
        bool can = true;
        for (int i = 0; i < 3; i++) {
            if (ids.count(rectangles[perm[i]].first)) can = false;
            rects.push_back({rectangles[perm[i]].second.first, rectangles[perm[i]].second.second});
        }
        if (!can) continue;

        can = false;

        can |= rects[0].h == rects[1].h && ((rects[0].w + rects[1].w) == rects[2].w) && (rects[0].h + rects[2].h == rects[2].w);
        can |= rects[0].h == rects[1].h && rects[1].h == rects[2].h && (rects[0].h == (rects[0].w + rects[1].w + rects[2].w));

        if (can) {
            cout << 1 << "\n";
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << 0 << "\n";
}