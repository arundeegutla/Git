#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();
    ll tot = 0;
    vector<int> arr(n);
    for(auto& x : arr) tot += x = nextInt();

    if(tot < k) {
        cout << "-1\n";
        return;
    }

    if(tot == k){
        cout << "0\n";
        return;
    }

    ll sum = 0;
    map<ll, int> end;
    for(int i = n-1; i >= 0; i--){
        if(arr[i]){
            sum++;
            end[sum] = n-i;
        }
    }

    sum = 0;
    int minn = end[tot-k];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        ll needToRemove = tot - sum - k;
        if(needToRemove < 0) break;
        minn = min(minn, end[needToRemove] + (i+1));
    }

    cout << minn << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}