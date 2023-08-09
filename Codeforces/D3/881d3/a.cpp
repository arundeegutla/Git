#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = n -1;
    ll sum = 0;
    while(l < r){
        sum += arr[r] - arr[l];
        l++;
        r--;
    }
    cout << sum << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}