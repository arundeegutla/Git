#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> lights(n);
    for (auto& x : lights) cin >> x;

    set<int> curLights;
    curLights.insert(0);
    curLights.insert(x);
    for (auto x : lights) curLights.insert(x);

    int maxx = 0;
    for (auto light : curLights) {
        auto next = curLights.upper_bound(light);
        if (next == curLights.end()) {
            continue;
        }

        maxx = max(maxx, (*next) - light);
    }

    vector<int> ans;
    ans.push_back(maxx);
    while (lights.size()) {
        int removing = lights.back();
        curLights.erase(removing);
        lights.pop_back();

        auto below = curLights.lower_bound(removing);
        below--;
        auto above = curLights.upper_bound(removing);

        maxx = max(maxx, (*above) - (*below));
        ans.push_back(maxx);
    }
    ans.pop_back();

    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}