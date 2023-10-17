#include <bits/stdc++.h>
using namespace std;
#define long long long

void solve() {
    int n; cin>>n;
    vector<long> arr(n);
    for(auto& x: arr) cin >> x;

    vector<long> s(n+1);
    vector<long> t(n+1);
    for(int i = 0; i<n; i++){
        s[i+1] = s[i] + arr[i];
        t[i+1] = t[i] + (arr[i]*arr[i]);
    }

    vector<vector<long>> dp(3, vector<long>(3));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        dp[s[i]%3][t[i]%3]++;

    for(auto oned : dp){
        for(auto x : oned){
            cout << x << " ";
        }
        cout << "\n";
    }

}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}