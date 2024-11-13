#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using S = array<pii, 2>;

int main() {
    int n, s, c;
    cin >> n >> s >> c;
    vector<int> schools(s + 1, c);
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        if (schools[p1]) {
            ct1++;
            schools[p1]--;
        } else if (schools[p2]) {
            ct2++;
            schools[p2]--;
        }
    }
    cout << ct1 << ' ' << ct2;
    return 0;
}