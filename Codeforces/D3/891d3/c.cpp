#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    ll n = nextInt();
    ll bSize = n*(n-1)/2;
    map<int, int> b;
    while(bSize--) b[nextInt()]++;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        if(!b.size()){
            a[i] = 1e9;
            continue;
        }
        auto p = (*(b.begin()));

        a[i] = p.first;
        if(p.second - (n-i-1) <= 0) {
            b.erase(p.first);
        } else {
            b[p.first] -= n-i-1;
        }
    }

    for(auto x : a)
        cout << x << " ";

    cout << "\n";



}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}