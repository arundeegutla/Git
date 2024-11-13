#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    ll oo = 1e18;
    vector<deque<ll>> grid(n);
    for(auto& arr : grid){
        int size = nextInt();
        while(size--) arr.push_back(nextInt());
        sort(all(arr));
    }

    ll minn = oo;
    vector<ll> sorted;
    for(auto arr : grid){
        minn = min(arr[0], minn);
        if(arr.size()==1){
            sorted.push_back(arr[0]);
        } else {
            sorted.push_back(arr[1]);
        }
    }

    sort(all(sorted));

    ll tot = minn;
    for(int i = 0; i < n-1; i++){
        tot += sorted.back();
        sorted.pop_back();
    }

    cout << tot << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}