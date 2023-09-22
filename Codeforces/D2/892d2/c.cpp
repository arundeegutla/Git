#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();

    vector<ll> perm(n);
    for(int i = 0; i < n; i++) perm[i] = i+1;

    ll finallmaxx = 0;
    for(int i = 0; i < n; i++){
        auto arr = perm;
        reverse(arr.begin()+n-i-1, arr.end());
        // for(auto x : arr) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        ll sum = 0;
        ll maxx = 0;
        for(int i = 1; i <= n; i++){
            sum += arr[i-1] * i;
            maxx = max(maxx, arr[i-1] * i);
        }
        finallmaxx = max(sum - maxx, finallmaxx);
    }

    cout << finallmaxx << "\n";

    

}

void check(){
    for(int n = 1; n <= 10; n++){
        vector<ll> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = i+1;
        }

        ll finalMaxx = 0;
        vector<ll> perm = arr;
        do {
            
            ll sum = 0;
            ll maxx = 0;
            for(int i = 1; i <= n; i++){
                sum += arr[i-1] * i;
                maxx = max(maxx, arr[i-1] * i);
            }

            if((sum - maxx) > finalMaxx) {
                finalMaxx = (sum - maxx);
                perm = arr;
            }

        } while(next_permutation(all(arr)));

    
        cout << n << ": ";
        for(auto x : perm) cout << x << " "; cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // check();
    int n = nextInt();
    while(n--) solve();
}