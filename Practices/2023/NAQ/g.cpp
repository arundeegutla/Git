#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, lph;
    cin >> n >> lph;

    vector<int> lines(n);
    for (auto& x : lines) cin >> x;

    sort(lines.begin(), lines.end());

    int total = 5 * 60;
    double minutes = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        double minutesTook = (lines[i] / (lph * 1.0)) * 60;
        if (minutes + minutesTook > total) {
            break;
        }
        minutes += minutesTook;
        count++;
    }
    cout << count << "\n";
}