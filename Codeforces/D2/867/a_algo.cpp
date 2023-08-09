#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
template<class T>

ostream & operator << (ostream & os, vector<T> v) {
    for (auto x : v) os << x << ' ';
     return os;
}


void solve(){

    int n,t; cin >> n >> t;
    vector<int> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i];
        times[i]+=i;
    }

    vector<int> values(n); for(auto &x: values) cin >> x;
    int ans = -1;
    int ind = -2;
    for(int i = 0; i < n; i++){
        if(times[i] <= t) {
            if(values[i] > ans){
                ans = values[i];
                ind = i;
            }
        }
            //ans = max(ans,values[i]);
    }

    cout << ind+1 << "\n";



}

int main(){
	//cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int cases; cin >> cases;
    while(cases--) solve();
	return 0;
}