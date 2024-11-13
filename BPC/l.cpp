#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, int>> ans;
    while (n--) {
        int id;
        double score;
        cin >> id >> score;
        ans.push_back({-score, id});
    }

    sort(ans.begin(), ans.end());

    set<int> ids;
    ids.insert(ans[0].second);
    ids.insert(ans[1].second);
    ids.insert(ans[2].second);

    for (auto x : ids) {
        cout << x << "\n";
    }
}