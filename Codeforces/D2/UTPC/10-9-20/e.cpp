#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    int XOR = 0;
    for(auto& x : arr) XOR ^= x = nextInt();

    if(!XOR) {
        cout << 0 << "\n";
        return;
    }
    
    cout << 1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}