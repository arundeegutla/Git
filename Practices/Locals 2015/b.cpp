#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<int> usa(3), russ(3);
        for (auto& x : usa) {
            cin >> x;
            cout << x << " ";
        }
        for (auto& x : russ) {
            cin >> x;
            cout << x << " ";
        }

        cout << "\n";
        int countU = accumulate(usa.begin(), usa.end(), 0);
        int countR = accumulate(russ.begin(), russ.end(), 0);

        bool count = countU > countR;
        bool color = usa[0] > russ[0] || (usa[0] == russ[0] && usa[1] > russ[1]) || (usa[0] == russ[0] && usa[1] == russ[1] && usa[2] > russ[2]);

        if (count && color) {
            cout << "both\n\n";
        } else if (count) {
            cout << "count\n\n";
        } else if (color) {
            cout << "color\n\n";
        } else {
            cout << "none\n\n";
        }
    }
}