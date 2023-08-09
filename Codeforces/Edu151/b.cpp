#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define y second
#define x first

void solve() {
    pair<int, int> alice = {nextInt(), nextInt()};
    pair<int, int> bobHome = {nextInt(), nextInt()};
    pair<int, int> carolHome = {nextInt(), nextInt()};  

    ll count = 1;

    if((bobHome.y <= alice.y && carolHome.y <= alice.y) || (bobHome.y >= alice.y && carolHome.y >= alice.y)) {
        count += min(abs(alice.y - bobHome.y), abs(alice.y - carolHome.y));
    }
    if(((bobHome.x <= alice.x && carolHome.x <= alice.x) || (bobHome.x >= alice.x && carolHome.x >= alice.x))) {
        count += min(abs(alice.x - bobHome.x), abs(alice.x - carolHome.x));
    }

    cout << count << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}