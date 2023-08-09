#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 0; i < (1<<n); i++){
        string big = bitset<16>(i).to_string();
        reverse(big.begin(), big.end());
        cout << big.substr(0, n) << "\n";
    }
}