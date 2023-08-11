#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    string s = next();
    sort(all(s));

    ll count = 0;
    ll all = 0;
    do {
        ll num = stoll(s);
        if(num%7 == 0){
            cout << num << "\n";
            count++;
        }
        all++;
    } while(next_permutation(all(s)));

    cout << count << " " << all << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}