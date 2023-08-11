#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    int k = nextInt();
    vector<string> arr(n);
    for(auto& x : arr) x = next();

    ll diff = 1e18;



    vector<int> perm(k);
    vector<int> used(k);

    auto go = [&](int at, auto&& go) -> void {
        if(at == k){

            ll maxx = -1e18;
            ll minn = 1e18;
            for(auto num : arr){
                ll x = 0;
                for(auto ind : perm){
                    x *= 10;
                    x += num[ind] - '0';
                }
                maxx = max(maxx, x);
                minn = min(minn, x);
            }
            diff = min(diff, maxx - minn);
            return;
        }

        for(int i = 0; i < k; i++){
            if(!used[i]){
                used[i] = true;
                perm[at] = i;
                go(at+1, go);
                used[i] = false;
            }
        }
    };

    go(0, go);

    cout << diff << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}