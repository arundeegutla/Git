#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int b, k;
        cin >> b >> k;

        vector<ll> bags(b);

        for(int i = 0; i < b; i++){
            int m;
            cin >> m;
            while(m--){
                ll x; cin >> x;
                bags[i] |= (1<<x);
            }
        }

        int maxx = 0;
        auto go = [&](int at, int have, ll took, auto&& go) -> void {
            if(at == b || have == k) {
                maxx = max(maxx, (int)bitset<32>(took).count());
                return;
            }
            go(at+1, have, took, go);
            go(at+1, have+1, took | bags[at], go);
        };

        go(0, 0, 0, go);

        cout << maxx << "\n";
    }
}