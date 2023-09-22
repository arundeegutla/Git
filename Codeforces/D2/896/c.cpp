#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    auto getMex = [&](set<int>& arr) -> int {
        for(int i = 0; i < m; i++)
            if(arr.find(i) == arr.end())
                return i;
        return m;
    };


    set<int> all;
    for(int j = 0; j < m; j++){
        int cur = j;
        set<int> arr;
        for(int i = 0; i < n; i++){    
            if(cur == j) {
                cur++;
                cur %= m;
            }

            grid[i][j] = cur;
            arr.insert(cur);
            cur++;
            cur %= m;
        }

        int mex = getMex(arr);
        all.insert(mex);
    }




    cout << getMex(all) << "\n";
    for(auto arr : grid) {
        for(auto x : arr){
            cout << x << " ";
        }
        cout << "\n";
    }


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}