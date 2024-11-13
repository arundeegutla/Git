#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    vector<int> arr = {nextInt(), nextInt(), nextInt()};
    if((arr[0]+arr[1] >= 10) || (arr[1] + arr[2] >= 10) || (arr[0] + arr[2] >= 10)){
        cout << "YES\n";
    } else {
        cout << "No\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}