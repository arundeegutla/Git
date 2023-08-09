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

    
    // vector<int> count(n);
    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < n; j++)
    //         for(int k = i; k <= j; k++)
    //             count[k]++;

    // for(auto x : count) cout << x << " ";
    // cout << "\n";

    int lc = 0;
    int rc = 0;
    int lat = 0;
    int rat = n-1;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        if(lc > rc || lc == rc){
            ans[rat] = arr[i];
            rat--;
            rc++;
        } else if (lc < rc){
            ans[lat] = arr[i];
            lat++;
            lc++;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << (i==n-1?"\n":" ");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("cubes.in", "r", stdin);
    int n = nextInt();
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}