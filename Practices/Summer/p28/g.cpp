#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("jenga.in", "r", stdin);
    int n = nextInt();
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ": " << (!(nextInt()%3) ? "Wahdan\n" : "Bakkar\n");
    }
}