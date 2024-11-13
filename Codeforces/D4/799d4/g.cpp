#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), k = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();
    vector<ll> psum(n);
    psum[0] = 1;
    int count = 0;
    for(int i = 1; i < n; i++){
        psum[i] = (2*arr[i] > arr[i-1]) + psum[i-1];

        if(i - k >= 0){
            int start = i - k + 1;
            ll sum = psum[i] - psum[start - 1];
            count += sum == k;

            // cout << i << " " << start << "\n";
            // for(auto x : psum) 
            //     cout << x << " ";
            // cout << sum << "\n";
        }
        
    }

    cout << count << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}