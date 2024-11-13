#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int x = abs(nextInt());
    int y = abs(nextInt());

    if(x==y)
        cout << 2*y << "\n";
    else if(x > y)
        cout << ((2*(x-y))-1) + 2*y << "\n";
    else 
        cout << ((2*(y-x))-1) + 2*x << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}