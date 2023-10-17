#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto& x : words) {
        cin >> x;
        sort(all(x));
    }


    unordered_map<char, int> bucket;
    vector<int> sizes(4);

    for(auto s : words) {
        int x, y, z;
        x = y = z = 0;
        
        if(bucket[s[0]] != 0) {
            x = 
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}