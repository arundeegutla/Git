#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int k = 1; k <= n; k++) {
        if (n % k != 0) continue;
        string prev = s.substr(0, k);
        rotate(prev.begin(), prev.end() - 1, prev.end());

        bool pass = true;
        int start = k;
        while (start < n && pass) {
            string cur = s.substr(start, k);
            pass &= prev == cur;
            prev = cur;
            rotate(prev.begin(), prev.end() - 1, prev.end());
            start += k;
        }

        if (pass) {
            cout << k << "\n";
            return 0;
        }
    }
}