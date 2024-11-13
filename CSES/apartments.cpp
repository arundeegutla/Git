#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> desired(n);
    vector<ll> houses(m);

    for (auto& x : desired) cin >> x;
    for (auto& x : houses) cin >> x;

    sort(desired.begin(), desired.end());
    sort(houses.begin(), houses.end());

    int took = 0;
    int houseAt = 0;
    for (int i = 0; i < n; i++) {
        while (houseAt < m && houses[houseAt] < desired[i] - k) {
            houseAt++;
        }
        if (houseAt == m) break;
        if (houses[houseAt] <= desired[i] + k) {
            took++;
            houseAt++;
        }
    }

    cout << took << "\n";
}
