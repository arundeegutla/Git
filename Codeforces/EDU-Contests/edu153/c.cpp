#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;


    int smallest = arr[0];
    int highest = 1e9;

    int count = 0;
    for(auto x : arr){
        smallest = min(smallest, x);
        if(smallest < x && x < highest){
            count++;
            highest = x;
        }
    }

    cout << count << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}