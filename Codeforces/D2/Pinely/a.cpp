#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int subs, online, notif;
    cin >> subs >> online >> notif;

    int guaranteed = online;
    string s; cin >> s;
    for(auto c : s) {
        if(guaranteed >= subs) {
            cout << "YES\n";
            return;
        }
        if(c == '-') guaranteed--;
        else guaranteed++;
    }
    if(guaranteed >= subs) {
        cout << "YES\n";
        return;
    }


    for(auto c : s) {
        if(c == '+') online++;
        if(online >= subs) {
            cout << "MAYBE\n";
            return;
        }
    }

    cout << "NO\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}