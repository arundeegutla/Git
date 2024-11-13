#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    set<int> drank;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        drank.insert(x);
    }

    bool hasMin = drank.find(a) != drank.end();
    bool hasMax = drank.find(b) != drank.end();

    if (!hasMin && !hasMax) {
        cout << -1 << "\n";
        return 0;
    }

    if (!hasMax) {
        cout << b << "\n";
        return 0;
    }

    if (!hasMin) {
        cout << a << "\n";
        return 0;
    }

    for (int i = a; i <= b; i++) {
        cout << i << "\n";
    }
}
