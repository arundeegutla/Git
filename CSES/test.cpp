#include <bits/stdc++.h>
using namespace std;

int main() {
    while (cin.good()) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') break;
            c++;
        }
        cout << "(" << x << ", " << c << ")\n";
    }
}