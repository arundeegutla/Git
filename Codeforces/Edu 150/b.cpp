#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int q = nextInt();
    vector<int> arr;
    bool moved = false;
    int prev = -1;
    int maxx = -1;
    while(q--){
        int num = nextInt();
        if(!moved && num >= prev){
            cout << 1;
            arr.push_back(num);
            maxx = max(maxx, num);
            prev = num;
        } else if(!moved && num <= arr[0]){
            moved = true;
            cout << 1;
            prev = num;
        } else if(moved && num <= arr[0] && num >= prev) {
            cout << 1;
            prev = num;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}