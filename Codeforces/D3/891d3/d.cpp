#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto& x : a) x = nextInt();
    for(auto& x : b) x = nextInt();

    vector<ll> c(n);
    for(int i = 0; i < n; i++)
        c[i] = a[i]-b[i];
    
    vector<ll> sorted = c;
    sort(all(sorted));

    set<int> arr;
    for(int i = 0; i < n; i++)
        if(c[i] == sorted[n-1])
            arr.insert(i+1);

    cout << arr.size() << "\n";
    for(auto x : arr) 
        cout << x << " ";
    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}