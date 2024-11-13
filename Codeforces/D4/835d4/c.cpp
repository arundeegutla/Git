#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    
    vector<int> s = arr;
    sort(s.begin(), s.end());
    int maxx = s[n-1];
    int secondMaxx = s[n-2];
    for(auto x : arr){
        if(x == maxx){
            cout << x - secondMaxx << " ";
        } else {
            cout << x - maxx << " ";
        }
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}