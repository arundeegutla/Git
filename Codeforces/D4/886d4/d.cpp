#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt(), k = nextInt();
    vector<int> arr(n);
    for(auto& x : arr)
        x = nextInt();
    sort(arr.begin(), arr.end());

    int maxx = 0;
    int count = 0;
    int prev = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] - prev <= k){
            count++;
        } else {
            count = 1;
        }
        prev = arr[i];
        maxx = max(maxx, count);
    }

    cout << n - maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}