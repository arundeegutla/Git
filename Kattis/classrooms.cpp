#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> events(n);
    for (auto& x : events) {
        cin >> x.second >> x.first;
    }

    sort(events.begin(), events.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return (a.first - a.second) < (b.first - b.second);
        }
        return a.first < b.first;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    while (k--)
        pq.push(0);

    int count = 0;
    for (auto [e, s] : events) {
        auto earliest = pq.top();
        if (earliest < s) {
            pq.pop();
            count++;
            pq.push(e);
        }
    }
    cout << count << "\n";
}
