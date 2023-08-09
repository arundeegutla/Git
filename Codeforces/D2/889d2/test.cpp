#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
vector<int>& nextIntArray(int n){vector<int> arr(n);for(auto& x : arr)x = nextInt();return arr;}
void printArray(vector<int> arr){for(auto x : arr) cout << x << " "; cout << "\n";}

void solve() {
    int n = nextInt();
    auto arr = nextIntArray(n);
    printArray(arr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}