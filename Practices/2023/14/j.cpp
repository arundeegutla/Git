#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    double maxx = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxx = max(maxx, (double)sum / (i + 1));
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += arr[i];
        maxx = max(maxx, (double)sum / (n - i));
    }

    cout << fixed << setprecision(10) << maxx << "\n";
}