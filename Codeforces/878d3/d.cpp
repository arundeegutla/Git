#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());

    string bits = bitset<64>(n).to_string();
    reverse(bits.begin(), bits.end());
    stoi(bits, nullptr, 2);

    

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}