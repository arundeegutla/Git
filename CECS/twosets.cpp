#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    ll half = (n*(n+1))/2;
    if(half % 2) {
        cout << "NO\n";
        return 0;
    }
    
    auto go = [&](int num, ll tot, auto&& go) -> bool {
        if(tot > half || num > n) return false;
        if(tot == half) return true;
        if(go(num+1, tot+num, go)){
            cout << num << " ";
            return true;
        }
        return go(num+1, tot, go);
    };

    cout << half << "\n";
    go(1, 0, go);
}