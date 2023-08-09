#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    int MOD = 1e9 + 7;
    ll cur = 1;
    while(n--){
        cur *= 2;
        cur %= MOD;
    }
    cout << cur << "\n";
}