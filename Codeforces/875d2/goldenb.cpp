#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N; cin >> N;

    int ac[400050] = {};
    int best{};
    for (int k = 0; k < 2; k++) {
        int curr{}, last{};
        for (int i = 0; i < N; i++) {
            int d; cin >> d;
            if (!k) {
                if (!i) {
                    curr++;
                    last = d;
                    ac[d]++;
                } else {
                    if (d == last) curr++;
                    else {
                        ac[last] = max(ac[last], curr);
                        curr = 1;
                        last = d;
                    }
                }
            } else {
                if (!i) {
                    curr++;
                    last = d;
                    best = max(best, ac[d]+1);
                } else {
                    if (d == last) curr++;
                    else {
                        best = max(best, ac[last]+curr);
                        curr = 1;
                        last = d;
                    }
                }
            }
        }


        if (!k) ac[last] = max(ac[last], curr);
        else best = max(best, ac[last] + curr);
    }
    
    cout << best << '\n';

}


int main() {
    int t; cin >> t;
    while (t--) solve();
}