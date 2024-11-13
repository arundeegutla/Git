#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
int RES;

const int MAXN = 1e5 + 5;

int parity[MAXN] = {0};
int mapp[MAXN] = {0};
int countEven[MAXN] = {0};

int main() {
    RES = 0;
    cin >> n >> m;

    ll cur;
    cin >> cur;
    parity[1] = cur % 2;
    countEven[1] = (parity[1] == 0);
    mapp[1] = 1;

    int start = 1;

    for (int i = 2; i <= n; i++) {
        char sign;
        cin >> sign >> cur;

        if (sign != '*') {
            RES += (countEven[start] == 0);
            start++;
        }

        parity[i] = cur % 2;
        mapp[i] = start;

        if (cur % 2 == 0)
            countEven[start]++;
    }

    RES += (countEven[start] == 0);

    /*
    for (int i = 1; i <= n; i++)
        cout << mapp[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; i++)
        cout << parity[i] << " ";
    cout << endl;

    for (int i = 1; i <= start; i++)
        cout << countEven[i] << " ";
    cout << endl;
    */

    cout << ((RES % 2) ? "odd" : "even") << endl;

    while (m--) {
        int x, y;
        cin >> x >> y;

        int par = y % 2;
        int parent = mapp[x];

        if (parity[x] == par) {
            cout << ((RES % 2) ? "odd" : "even") << endl;
            continue;
        }

        parity[x] = par;

        if (par == 1) {
            --countEven[parent];
            if (countEven[parent] == 0)
                RES++;
        }

        else if (++countEven[parent] == 1)
            RES--;
        /*
        for (int i = 1; i <= n; i++)
            cout << parity[i] << " ";
        cout << endl;

        for (int i = 1; i <= start; i++)
            cout << countEven[i] << " ";
        cout << endl;
        */

        cout << ((RES % 2) ? "odd" : "even") << endl;
    }
}