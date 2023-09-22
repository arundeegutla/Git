#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string s;
    cin >> s;

    ll tot = 0;

    ll a = 0;
    ll b = 0;
    priority_queue<int> pq;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            a++;
        } else {
            pq.push(a);
            a = 0;
            b++;
        }
    }
    pq.push(a);

    while(b-- && pq.size()){
        tot += pq.top();
        pq.pop();
    }

    cout << tot << "\n";



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}