#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        bool zack = false;
        bool mack = false;

        vector<int> arr(10);
        for (auto& x : arr) {
            cin >> x;
            zack |= x == 17;
            mack |= x == 18;
        }

        for (auto x : arr) cout << x << " ";
        cout << "\n";
        if (mack && zack) {
            cout << "both\n\n";
        } else if (mack) {
            cout << "mack\n\n";
        } else if (zack) {
            cout << "zack\n\n";
        } else {
            cout << "none\n\n";
        }
    }
}