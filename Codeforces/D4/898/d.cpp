#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int start = -1;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            if(start == -1) {
                start = i;
            }
        }

        if(start != -1 && i - start + 1 == k) {
            start = -1;
            count++;
        }
    }

    cout << count + (start != -1) << "\n";



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}