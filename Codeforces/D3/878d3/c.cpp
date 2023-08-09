#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();
    int q = nextInt();

    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    ll total = 0;
    int i = 0;
    for(ll i = 0; i < n; i++){
        if(arr[i] > q) continue;
        int start = i;
        while (i < n && arr[i] <= q) i++;
        ll num = max(0LL, (i - (start+(k-1))));
        total += max(0LL, (num*(num+1))/2);
    }
    
    cout << total << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}