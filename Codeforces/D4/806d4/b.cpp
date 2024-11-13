#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    string s = next();

    map<char, int> hmpa;
    for(auto c : s)
        hmpa[c] += (!hmpa[c] ? 2 : 1);

    int count = 0;
    for(auto [k, v] : hmpa)
        count += v;

    cout << count << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}