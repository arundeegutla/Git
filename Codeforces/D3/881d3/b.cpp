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

    ll sum = 0;
    ll count = 0;
    bool neg = false;
    for(auto x : arr){
        if(x <= 0){
            if(x < 0 && !neg){
                neg = true;
                count++;
            }
            sum += -x;
        } else {
            neg = false;
            sum += x;
        }
    }
    cout << sum << " " << count << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}