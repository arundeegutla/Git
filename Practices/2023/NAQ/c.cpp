#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

using Food = pair<int, ld>;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<ld, int>> food(n);
    for (auto& [e, f] : food) {
        cin >> f >> e;
        e--;
    }

    auto mySort = [](Food& a, Food& b) -> bool {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    };
    auto can = [&](ld need) -> bool {
        priority_queue<Food, vector<Food>, decltype(mySort)> pq(mySort);

        for (int day = 0; day < n; day++) {
            ld needToEat = need * k;
            pq.push(food[day]);
            while (needToEat > 0 && pq.size()) {
                auto [exp, available] = pq.top();
                pq.pop();

                // expired.
                if (exp < day) continue;

                ld take = min(needToEat, available);
                available -= take;
                needToEat -= take;
                if (available > 0) {
                    pq.push({exp, available});
                }
            }
            if (needToEat > 0)
                return false;
        }

        return true;
    };

    ld lo = 0;
    ld hi = 1e10;
    ld ans = -1;
    for (int i = 0; i < 70; i++) {
        ld mid = (lo + hi) / 2;
        if (can(mid)) {
            lo = mid;
            ans = mid;
        } else {
            hi = mid;
        }
    }

    if (ans <= 0) {
        cout << -1 << "\n";
    } else {
        cout << fixed << setprecision(10) << ans << "\n";
    }
}