#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextInt(), c = nextInt(), d = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());

    ll minn = (c*n)+d;
    int have = 0;
    unordered_set<int> nums;
    for(int i = 0; i < arr.size(); i++) {
        int perm = arr[i];
        nums.insert(perm);
        ll have = nums.size();
        ll doopsHere = (i+1) - nums.size();
        ll remove = n - have - doopsHere;
        ll cost = doopsHere * c;
        cost += remove * c;
        cost += (perm - have) * d;
        minn = min(minn, cost);
    }
    cout << minn << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}