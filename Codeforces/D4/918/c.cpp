#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    vector<string> arr(3);
    for (auto& s : arr) cin >> s;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == '?') {
                bool a = false;
                bool b = false;
                bool c = false;

                for (int k = 0; k < 3; k++) {
                    a |= arr[i][k] == 'A';
                    a |= arr[k][j] == 'A';

                    b |= arr[i][k] == 'B';
                    b |= arr[k][j] == 'B';

                    c |= arr[i][k] == 'C';
                    c |= arr[k][j] == 'C';
                }

                if (!a) {
                    cout << "A\n";
                } else if (!b) {
                    cout << "B\n";
                } else {
                    cout << "C\n";
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}