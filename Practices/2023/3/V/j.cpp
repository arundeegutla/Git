#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    while(k--){
        string a, b;
        for(int i = 0; s.size(); i++){
            if(i%2)
                a.push_back(s.back());
            else
                b.push_back(s.back());
            s.pop_back();
        }
        s = a + b;
    }
    
    cout << s << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}