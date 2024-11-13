#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int pairsNotMatching = 0;
    int l = 0;
    int r = n-1;
    while(l < r){
        pairsNotMatching += s[l] != s[r];
        l++;
        r--;
    }

    string ret;
    for(int i = 0; i <= n; i++){
        if(i < pairsNotMatching || (n-i < pairsNotMatching)){
            ret.push_back('0');
            continue;
        }

        if((i - pairsNotMatching) % 2 == 0 || n % 2) {
            ret.push_back('1');
        } else {
            ret.push_back('0');
        }
    }

    cout << ret << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}