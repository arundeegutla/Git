// Banger of the set.
// Just subtract available from requested
// and if the answer is positive there are
// that many people unsatisfied

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3), b(3);

    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> b[i];

    int res = 0;

    for (int i = 0; i < 3; i++)
        res += max(b[i] - a[i], 0);

    cout << res << endl;
}