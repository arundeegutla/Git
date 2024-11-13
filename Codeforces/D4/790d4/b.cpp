#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    long sum = 0;
    int min = arr[0];
    for(auto x : arr){
        sum += x-min;
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}