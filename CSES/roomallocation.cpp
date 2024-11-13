#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> customers(n);
    for (auto& [x, y] : customers)
        cin >> x >> y;
    sort(customers.begin(), customers.end());

    using info = pair<int, int>;
    auto mySort = [&](info& a, info& b) -> bool {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    };
    auto can = [&](int numRooms) -> pair<bool, vector<int>> {
        vector<int> assigned(n);
        priority_queue<info, vector<info>, decltype(mySort)> pq(mySort);
        for (int i = 0; i < numRooms; i++)
            pq.push({0, i});

        for (int i = 0; i < n; i++) {
            auto [start, end] = customers[i];
            auto [time, roomNo] = pq.top();
            pq.pop();
            if (time >= start) return {false, {}};
            assigned[i] = roomNo;
            pq.push({end + 1, roomNo});
        }
        return {true, assigned};
    };

    int lo = 0;
    int hi = n;
    int ans = -1;
    vector<int> assigned;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        auto [what, ass] = can(mid);
        if (what) {
            hi = (ans = mid) - 1;
            assigned = ass;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
    for (auto x : assigned) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}