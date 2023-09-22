#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(all(arr));

    vector<int> b;
    vector<int> c;
    int i = 0;
    int prev = -1;
    while(i < n && (arr[i] == prev || prev == -1)) {
        b.push_back(arr[i]);
        prev = arr[i];
        i++;
    }

    while(i < n){
        c.push_back(arr[i]);
        i++;
    }

    if(c.size()){
        cout << b.size() << " " << c.size() << "\n";
        for(auto x : b) cout << x << " "; cout << "\n";
        for(auto x : c) cout << x << " "; cout << "\n";
    } else {
        cout << "-1\n";
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}