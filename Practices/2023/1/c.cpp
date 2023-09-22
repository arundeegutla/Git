#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> wormhole(n);
    while(k--){
        int x;
        cin >> x;
        x--;
        wormhole[x] = true;
    } 


}