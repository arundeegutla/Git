#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    int sumA = 0;
    for (auto& [x, y] : tasks) {
        cin >> x >> y;
        sumA += x;
    }

    using ll = long long;
    using vi = vector<ll>;
    using vvi = vector<vi>;

    vvi memo()
}