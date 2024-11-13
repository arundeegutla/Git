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

    ll tot = 0;
    int ones = 0;
    int zeroes = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]) ones++;
        else{
            tot += ones;
            zeroes++;
        }
    }



    ones = 0;
    ll maxx = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]){
            ll count = tot - zeroes + ones;
            maxx = max(maxx, count);
            ones++;
        } else {
            zeroes--;
            ll count = tot - ones + zeroes;
            maxx = max(maxx, count);
        }
    }

    cout << max(maxx, tot) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}