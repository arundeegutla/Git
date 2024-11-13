#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    int printed = false;
    while (n--) {
        int x;
        cin >> x;
        while (cur != x) {
            cout << cur << "\n";
            printed = true;
            cur++;
        }
        cur++;
    }
    if (!printed) {
        cout << "good job\n";
    }
}