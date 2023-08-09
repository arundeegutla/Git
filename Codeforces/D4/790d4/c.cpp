#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(auto& x : arr)
        cin >> x;

    int minn = (int)1e9;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int tot = 0;
            for(int k = 0; k < m; k++)
                tot += abs(arr[i][k] - arr[j][k]);
            minn = min(minn, tot);
        }
    }
    
    cout << minn << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}