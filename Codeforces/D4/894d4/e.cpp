#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    vector<int> arr;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int x = nextInt();
        sum += x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    
    for(int i = 0; i+1 < n; i++) {
        ll thisSum = sum - arr[i] - arr[i+1] - arr[i] - arr[i+1];
        if(thisSum >= sum){
            sum = thisSum;
            i++;
        }
    }
    
    cout << sum << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}