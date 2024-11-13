#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2) {
        cout << 0 << "\n";
        return 0;
    }

    if ((n / 2) % 2) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}