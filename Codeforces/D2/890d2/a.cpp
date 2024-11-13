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
    for(auto& x : arr) x= nextInt();

    int maxx = 0;
    for(int i = 0; i+1 < n; i++)
        if(arr[i] > arr[i+1])
            maxx = max(maxx, arr[i]);
    cout << maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}