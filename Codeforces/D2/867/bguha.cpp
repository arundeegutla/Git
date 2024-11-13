using namespace std;
#include <bits/stdc++.h>
typedef long long ll;

int main() {

    int nC;
    cin >> nC;

    for (int loop=0; loop<nC; loop++) {

        int n;
        cin >> n;
        ll val;
        vector<ll> vals;
        for (int i=0; i<n; i++) {
            cin >> val;
            vals.push_back(val);
        }
        sort(vals.begin(), vals.end());

        if (vals.size() == 2) {
            cout << vals[0]*vals[1] << endl;
        }
        else {

            // cases...
            ll a = vals[0]*vals[1];
            ll b = vals[n-1]*vals[n-2];
            ll res = a > b ? a : b;
            cout << res << endl;

        }
    }

    return 0;
}
