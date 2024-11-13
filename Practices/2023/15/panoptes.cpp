#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;

    double sum = 0;
    vector<double> arr(n);
    for (auto& x : arr) {
        cin >> x;
        sum += x;
    }

    double avg = sum / n;

    vector<bool> decreased(n);
    for (int i = 0; i < n; i++) {
        decreased[i] = arr[i] < 0.8 * avg;
    }

    for (int i = p; i <= n; i++) {
        for (int start = 1; start <= i; start++) {
            bool possible = true;
            for (int at = start; at <= n; at += i) {
                possible &= decreased[at - 1] && (at - i < 1 || decreased[at - i - 1]);
            }
            if (possible) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
}