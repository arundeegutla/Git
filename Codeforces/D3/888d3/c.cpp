#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextInt(), k = nextInt();
    vector<int> colors(n);
    for(auto& x : colors) x = nextInt();

    int ones = colors[0];
    int last = colors[n-1];


    int o = 0;
    int c = 0;
    for(int i = 0; i < n && c < k; i++){
        if(o < k){
            o += colors[i] == ones;
        }
        else if(o == k){
            c += colors[i] == last;
        }
    }

    // cout << o << " " << c << '\n';
    cout << (((o == k && c >= k) || (o==k && last == ones)) ? "YES\n" : "NO\n");

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}