#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e5 + 5;

ll n, q;
string s;
int num;
int d_c, d_r;

ll res;

bool rows[MAXN] = {false};
bool cols[MAXN] = {false};

bool inBounds(int x) {
    return (0 < x && x <= n);
}

void query() {
    int i = num;
    if (s[0] == 'R') {
        if (inBounds(i-1)) {
            if (rows[i-1] == rows[i]) {
                res -= d_r;
                d_c--;
            }
            else {
                res += d_r;
                d_c++;
            }
        }

        if (inBounds(i+1)) {
            if (rows[i+1] == rows[i]) {
                res -= d_r;
                d_c--;
            }
            else {
                res += d_r;
                d_c++;
            }
        }

        rows[i] = !rows[i];
    }

    else {
        if (inBounds(i-1)) {
            if (cols[i-1] == cols[i]) {
                res -= d_c;
                d_r--;
            }
            else {
                res += d_c;
                d_r++;
            }
        }

        if (inBounds(i+1)) {
            if (cols[i+1] == cols[i]) {
                res -= d_c;
                d_r--;
            }

            else {
                res += d_c;
                d_r++;
            }
        }

        cols[i] = !cols[i];
    }
}

int main() {
    cin >> n >> q;
    res = n*n;
    d_r = d_c = n;

    while (q--) {
        cin >> s >> num;
        query();

        cout << res << endl;
    }
}